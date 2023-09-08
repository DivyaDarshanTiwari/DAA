#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

void divide(int arr[], int s, int e);
void conquer(int arr[], int s, int mid, int e);
void renderGraph(SDL_Renderer *renderer, double x[], double y[], int len);

int main()
{
    int max_elements = 10000; // Maximum number of elements to test
    int step_size = 100;      // Step size for increasing array size
    int num_tests = max_elements / step_size;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Sorting Algorithm Performance", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL)
    {
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
        return 1;
    }

    int num_points = max_elements / step_size;
    double x[num_points];
    double y[num_points];

    FILE *csvFile = fopen("sorting_data.csv", "w");
    if (csvFile == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    fprintf(csvFile, "Array Size,Time Taken (s)\n"); // Header

    for (int i = step_size; i <= max_elements; i += step_size)
    {
        int arr[i];
        for (int j = 0; j < i; j++)
        {
            arr[j] = rand() % 10000;
        }

        clock_t start = clock();
        divide(arr, 0, i - 1);
        clock_t end = clock();
        double timetaken = (double)(end - start) / CLOCKS_PER_SEC;

        fprintf(csvFile, "%d,%lf\n", i, timetaken); // Write data to CSV

        // Store data for graph
        x[i / step_size - 1] = i;
        y[i / step_size - 1] = timetaken;
    }

    fclose(csvFile);
    printf("Data saved to sorting_data.csv\n");

    // Render the graph
    renderGraph(renderer, x, y, num_points);

    // Wait for the user to close the window
    SDL_Event e;
    int quit = 0;
    while (!quit)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                quit = 1;
            }
        }
    }

    // Clean up SDL
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

void divide(int arr[], int s, int e)
{
    if (s < e)
    {
        int mid = s + (e - s) / 2;
        divide(arr, s, mid);
        divide(arr, mid + 1, e);
        conquer(arr, s, mid, e);
    }
}

void conquer(int arr[], int s, int mid, int e)
{
    int merged[e - s + 1];
    int index1 = s;
    int index2 = mid + 1;
    int x = 0;
    while (index1 <= mid && index2 <= e)
    {
        if (arr[index1] <= arr[index2])
        {
            merged[x] = arr[index1];
            x++;
            index1++;
        }
        else
        {
            merged[x] = arr[index2];
            x++;
            index2++;
        }
    }
    while (index1 <= mid)
    {
        merged[x] = arr[index1];
        x++;
        index1++;
    }
    while (index2 <= e)
    {
        merged[x] = arr[index2];
        x++;
        index2++;
    }
    for (int i = 0, j = s; i < x; i++, j++)
    {
        arr[j] = merged[i];
    }
}

void renderGraph(SDL_Renderer *renderer, double x[], double y[], int len)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Blue color for the graph
    for (int i = 1; i < len; i++)
    {
        SDL_RenderDrawLine(renderer, x[i - 1], 600 - y[i - 1], x[i], 600 - y[i]);
    }

    SDL_RenderPresent(renderer);
}
