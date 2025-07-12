#include<stdio.h>
#include<time.h>

void TOH(int n, char src, char dst, char tmp)
{
    if(n==1)
    {
        printf("Move Disk %d from %c to %c\n", n,src,dst);
    }
    else{
        TOH(n-1, src,tmp, dst);
        printf("move disk %d from %c to %c\n", n,src,dst);
        TOH(n-1, tmp,dst,src);
    }
}

int main()
{
    int n,result;
    printf("Enter the number\n");
    scanf("%d",&n);
    clock_t start,end;
    start=clock();

    TOH(n,'A','B','C');
    end=clock();
    double diff=((double)(end-start))/CLOCKS_PER_SEC;
    printf("result: %lf\n",diff);
}