#include <stdio.h>
#include<time.h>
#include<stdlib.h>

void divide(int arr[], int s, int e);
void conquer(int arr[], int s, int mid, int e);

int main()
{
    int az;
    printf("Enter the Size of the array:");
    scanf("%d", &az);
    int arr[az];
    int len = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<len;i++)
    {
        arr[i]=rand()%10000;
    }
    clock_t start = clock();
    divide(arr, 0, len - 1);
    clock_t end = clock();
    double timetaken = (double) (end-start) / CLOCKS_PER_SEC;
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]); 
    }
    printf("\n The Time taken =%lf pee sec", timetaken);
    return 0;
}

void divide(int arr[], int s, int e)
{
    if (s < e)
    {
        int mid = s + e  / 2;
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
