#include <stdio.h>
#include <time.h>
#include<stdlib.h>

int main() 
{
    int n[100000];
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

    printf("\nTime taken for Selection Sort: %lf seconds\n", time_taken);

    return 0;
}
