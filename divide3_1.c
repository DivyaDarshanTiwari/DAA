#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void quicksort(int a[],int v ,int mid, int q);

int main()
{
    int n,mid;
    printf("Enter the No. of elements in array:");
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i]= rand()%10000;
    }
    mid = n /2;
    quicksort(arr, 0, mid, n-1);
    printf("The sorted array is:");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    
}

void quicksort(int a[], int v, int mid, int q)
{
    if
}