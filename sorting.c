#include<stdio.h>
#include<time.h>
#include<stdlib.h>

double bubblesort(int az);
double selectsort(int az);

int main()
{
    int n;
    printf("Enter the size of array for which you want to find out the time");
    scanf("%d", &n);
    double bubble_time = bubblesort(n);
    double select_time = selectsort(n);
    printf("\nTime taken for bubble Sort: %lf seconds\n", bubble_time);
    printf("\nTime taken for Selection Sort: %lf seconds\n", select_time);
}

double bubblesort(int az)
{
    int n[az];
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
    return timetaken;
}

double selectsort(int az)
{
    int n[az];
    int size = sizeof(n)/sizeof(n[0]);
    for(int i=0;i<size;i++)
    {
        n[i]=rand()%10000;
    }
    int c =0;
    printf("Original array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", n[i]);
    }

    clock_t start_time = clock();

    for (int i = 0; i < size - 1; i++) {
        int min_ind = i;
        for (int j = i + 1; j < size; j++) {
            if (n[min_ind] > n[j]) {
                min_ind = j;
                c++;
            }
        }
        int a = n[i];
        n[i] = n[min_ind];
        n[min_ind] = a;
    }

    clock_t end_time = clock();
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("\nSorted array in ascending order:\n");
    for (int i = 0; i < size; i++) {
        printf("\n %d ", n[i]);
    }

    return time_taken;
}