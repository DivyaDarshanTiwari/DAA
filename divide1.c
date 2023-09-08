#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linearsearch( int a[], int n , int i , int k);
int binarysearch(int a[], int i, int l, int x); 
void selectsort(int n, int *arr); 

int main()
{
    int n,i=0;
    printf("Enter the size of the array for which you want to find out the time: ");
    scanf("%d", &n);
    int n_array[n]; 
    int m_array[n];
    for (int i = 0; i < n; i++)
    {
        n_array[i] = rand() % 100000;
        m_array[i]= n_array[i];
    }

    int k;
    printf("Enter the element to search: ");
    scanf("%d", &k);
    selectsort(n, n_array);

    clock_t start = clock();
    int index = binarysearch(n_array, 0, n - 1, k); 
    clock_t end_time = clock();
    double time_taken = (double)(end_time - start)*1000 / CLOCKS_PER_SEC;
    printf("The element is found at index %d of binary search\n",index);
    clock_t startt =clock();
    int index1 = linearsearch(m_array,n,i,k);
    clock_t endd = clock();
    double time = (double)(endd- startt) *1000 / CLOCKS_PER_SEC;
    printf("The element is found at index %d of linear search\n",index1);
    printf("The time taken by the linear search to search the element: %lf seconds\n", time);
    printf("The time taken by the binary search to search the element: %lf seconds\n", time_taken); 
    return 0;
}

int linearsearch( int a[], int n , int i , int k)
{
    if(i>=n)
    {
        return -1;
    }
    else
    {
        if(a[i]== k)
        return i;
        else
        return linearsearch(a, n, i+1, k);
    }
}

int binarysearch(int a[], int i, int l, int x) 
{
    if (i > l)
    {
        return -1;
    }
    else
    {
        int mid = (i + l) / 2;
        if (x == a[mid])
        {
            return mid; 
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
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        int min_ind = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[min_ind] > arr[j]) {
                min_ind = j;
            }
        }
        int a = arr[i];
        arr[i] = arr[min_ind];
        arr[min_ind] = a;
    }
    printf("\nSorted array in ascending order:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
