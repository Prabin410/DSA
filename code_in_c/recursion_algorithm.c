#include <stdio.h>

int tailfact(int n, int a)
{
    if (n == 1)
        return a;          
    else
        return tailfact(n - 1, a * n);
}



int main()
{
    int result;
    result = tailfact(5, 3);
     printf("%d", result); 
   

    return 0;

}
