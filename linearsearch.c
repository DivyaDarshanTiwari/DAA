#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double linearsearch(int n);

int main()
{
    int n;
    printf("Enter the size of the array for which you want to find out the time: ");
    scanf("%d", &n);
    double time = linearsearch(n);
    printf("The time taken by the linear search to search the element: %lf seconds", time);
    return 0;
}

double linearsearch(int az)
{
    int n[az];
    int arg_size = az;
    for (int i = 0; i < arg_size; i++)
    {
        n[i] = rand() % 10000;
    }

    int k;
    printf("Enter the element to search: ");
    scanf("%d", &k);

    clock_t start = clock();
    int index;
    for (index = 0; index < arg_size; index++)
    {
        if (n[index] == k)
          break;
    }

    if (index < arg_size)
        printf("Element %d found at index %d\n", k, index);
    else
        printf("Element %d not found\n", k);

    clock_t end_time = clock();
    double time_taken = (double)(end_time - start) / CLOCKS_PER_SEC;

    return time_taken;
}