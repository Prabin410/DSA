#include<stdio.h>
 int GCD(int a,int b)
 {
  if (b==0)
   return a;
   else
   return GCD(b,a%b);
}
int main()
{
    int result;
    result=GCD(6,8);
    printf("%d",result);

    return 0;
}