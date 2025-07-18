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
    int result_is;
    result_is=GCD(6,8);
    printf("%d",result_is);

    return 0;
}