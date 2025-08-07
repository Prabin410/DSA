#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10000
void selection_sort(int A[], int n)
{
    int least, pos, j, i, temp;
    for (i = 0; i < n; i++)
    {
        least = A[i];
        pos = i;
    
    for (j = i + 1; j < n; j++) // adjacent number compare garna hunxa
    {
        if (A[j] < least)
        {
            least = A[j];
            pos = j;
        }
    }
        if (i != pos)
        {
           
            temp = A[i];
            A[i] = A[pos];
            A[pos] = temp;
        }
    }
}

void display(int A[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
int main()
{
    int A[MAX], n, i;
    clock_t start, end;
    double diff;
    printf("How Many Elements");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        A[i] = rand() % 1000;
    }
    display(A, n);
    start = clock();
    selection_sort(A, n);
    end = clock();
    diff = ((double)(end - start) / CLOCKS_PER_SEC);
    display(A, n);
    printf("Time Taken is %lf seconds\n", diff);
    return 0;
}
