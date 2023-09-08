#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarysearch(int a[], int i, int l, int x); // Updated function signature
void selectsort(int n, int *arr);

int main()
{
    int n;
    printf("Enter the size of the array for which you want to find out the time: ");
    scanf("%d", &n);
    
    int n_array[n]; // Declare the array to be used
    for (int i = 0; i < n; i++)
    {
        n_array[i] = rand() % 10000;
    }

    int k;
    printf("Enter the element to search: ");
    scanf("%d", &k);
    selectsort(n, n_array);

    clock_t start = clock();
    int index = binarysearch(n_array, 0, n - 1, k); // Call binarysearch with the correct arguments
    clock_t end_time = clock();
    double time_taken = (double)(end_time - start) / CLOCKS_PER_SEC;

    if (index != -1) // Check if the element was found
        printf("Element %d found at index %d\n", k, index);
    else
        printf("Element %d not found\n", k);

    printf("The time taken by the binary search to search the element: %lf seconds\n", time_taken);
    
 // Call selectsort to sort the array
    return 0;
}

int binarysearch(int a[], int i, int l, int x) // Updated function signature and return type
{
    if (i > l)
    {
        return -1; // Element not found
    }
    else
    {
        int mid = (i + l) / 2;
        if (x == a[mid])
        {
            return mid; // Element found
        }
        else
        {
            if (x < a[mid])
                return binarysearch(a, i, mid - 1, x);
            else
                return binarysearch(a, mid + 1, l, x);
        }
    }
}

void selectsort(int n, int *arr)
{
    printf("Original array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    for (int i = 0; i < n - 1; i++)
    {
        int min_ind = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[min_ind] > arr[j])
            {
                min_ind = j;
            }
        }
        int a = arr[i];
        arr[i] = arr[min_ind];
        arr[min_ind] = a;
    }
    printf("\nSorted array in ascending order:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
