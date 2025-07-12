
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100000

void merge(int A[], int l, int m, int r)
{
    int i = l, j = m, k = l, B[MAX];

    while (i < m && j <= r)
    {
        if (A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    for (; i < m; i++, k++)
        B[k] = A[i];

    for (; j <= r; j++, k++)
        B[k] = A[j];

    for (k = l; k <= r; k++)
        A[k] = B[k];
}

void merge_sort(int A[], int l, int r)
{
    int m;
    if (l < r)
    {
        m = (l + r) / 2;

        merge_sort(A, l, m);
        merge_sort(A, m + 1, r);
        merge(A, l, m + 1, r);
    }
}

void display(int A[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n\n\n");
}

int main()
{
    int i, n, A[MAX];

    clock_t start, end;
    double time_taken;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        A[i] = rand() % 1000;
    }
    // display(A, n);

    start = clock();
    merge_sort(A, 0, n - 1);
    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    // display(A, n);
    printf("Time taken is %lf seconds\n", time_taken);
    return 0;
}
