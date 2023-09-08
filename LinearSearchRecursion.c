#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int linearsearch(int a[],int n, int i, int k);

int main()
{
    int az,k,i=0;
    printf("Enter the Size of the array:");
    scanf("%d", &az);
    int arr[az];
    int len = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<len;i++)
    {
        arr[i]=rand()%10000;
    }
    printf("Enter the element to be searched ");
    scanf("%d",&k);
    clock_t start =clock();
    int index = linearsearch(arr, len, i, k);
    clock_t end =  clock();
    double time = (double) (end-start) / CLOCKS_PER_SEC;
    if(k!=-1)
    printf("The elemnt is found at index %d \n", index);
    else
    printf("The element is not found");
    printf("The time taken to perfom the task is %lf \n", time);

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