#include <stdio.h>
#include <stdlib.h>

int fib_int(int n)
{
   if(n==0)
    return 0;
   else if(n==1)
    return 1;
   else
    return fib_int(n-2)+fib_int(n-1);
}

long fib_long(int n)
{
    if(n==0)
    return 0;
   else if(n==1)
    return 1;
   else
    return fib_long(n-2)+fib_long(n-1);
}

unsigned int fib_unint(int n)
{
    if(n==0)
    return 0;
   else if(n==1)
    return 1;
   else
    return fib_unint(n-2)+fib_unint(n-1);
}

unsigned long fib_unlong(int n)
{
    if(n==0)
    return 0;
   else if(n==1)
    return 1;
   else
    return fib_unlong(n-2)+fib_unlong(n-1);
}

int main()
{
    int n=0;
    while(1)
    {
       if(fib_int(n+1)<fib_int(n))
           break;
        n++;
    }
    printf("int的n为%d\n",n);
    n=0;

    while(1)
    {
       if(fib_long(n+1)<fib_long(n))
           break;
        n++;
    }
    printf("long的n为%d\n",n);
    n=0;

    while(1)
    {
       if(fib_unint(n+1)<fib_unint(n))
           break;
        n++;
    }
    printf("unsigned int的n为%d\n",n);
    n=0;

    while(1)
    {
       if(fib_unlong(n+1)<fib_unlong(n))
           break;
        n++;
    }
    printf("unsigned long的n为%d\n",n);
    return 0;
}
