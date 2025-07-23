#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100000

int partition(int A[],int l, int r)
{
int x = l, y = r, pivot = A[l], temp;
while(x<y)
{
    
    while (A[x] <= pivot && x <= r)
        x++;
    while (A[y] > pivot && y >= 1)
        y--;

    if(x<y)
    {
        temp = A[x];
        A[x] = A[y];
        A[y] = temp;
    }
}
A[l] = A[y];
A[y] = pivot;
return y;

}


void quick_sort(int A[], int l, int r)
{
    if (l<r)
    {
        int p = partition(A,l,r);
        quick_sort(A,l,p-1);
        quick_sort(A,p+1,r);
    }
}
void display(int A[],int n)
{
    int i;
    for (i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}

int main(){
    int A[MAX],n,i;
    clock_t start, end;
    double diff;
    printf("How many element: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        A[i] = rand()%1000;
    }
    display(A,n);
    start = clock();

    quick_sort(A,0,n-1);
    end = clock();
    diff = difftime(end,start) / CLOCKS_PER_SEC;
    display(A,n);
    printf("TIme Taken is %lf seconds\n",diff);
return 0;


}