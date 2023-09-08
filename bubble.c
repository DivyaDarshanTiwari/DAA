#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main()
{
    int n[500000];
    int arg_size = sizeof(n)/sizeof(n[0]);
    for(int i=0;i<arg_size;i++)
    {
        n[i]=rand()%10000;
    }
    int a =0;
    for (int i = 0; i < arg_size; i++)
    {
        printf("%d ", n[i]);
    }
    clock_t start = clock();
    for (int j = 0; j < arg_size; j++)
    {
    for(int i=0; i<arg_size-1; i++)
    {
        if(n[i]<n[i+1])
        {
            a=n[i];
            n[i]=n[i+1];
            n[i+1]=a;
        }
    }
    }
    clock_t end = clock();
    double timetaken = (double) (end-start) / CLOCKS_PER_SEC;
    for (int i = 0; i < arg_size; i++)
    {
        printf("\n %d ", n[i]);
    }
    printf(" \n Time taken %f", timetaken);
    return 0;
}