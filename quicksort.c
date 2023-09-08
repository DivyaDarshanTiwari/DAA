#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void divide(int a[], int p, int q);
int conquer(int a[], int p, int q);

int main() {
    printf("Enter the no. of elements:");
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 1000;
    }

    time_t start = clock();
    divide(a, 0, n - 1);
    time_t end = clock();
    double timetaken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\nTime taken: %f seconds\n", timetaken);

    return 0;
}

void divide(int a[], int p, int q) {
    if (p < q) {
        int v = conquer(a, p, q);
        divide(a, p, v - 1);
        divide(a, v + 1, q);
    }
}

int conquer(int a[], int p, int q) {
    int v = p;
    int t;
    while (p <= q) {
        while (a[p] <= a[v]) {
            p++;
        }
        while (a[q] > a[v]) {
            q--;
        }
        if (p < q) {
            t = a[p];
            a[p] = a[q];
            a[q] = t;
        }
    }
    t = a[v];
    a[v] = a[q];
    a[q] = t;
    return q;
}
