#include <stdio.h>
#include <stdlib.h>

int fib_int(int n)
{
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    int a=0,b=1,c;
    for(int i=2;i<=n;i++)
    {
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}

long fib_long(int n)
{
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    long a=0,b=1,c;
    for(int i=2;i<=n;i++)
    {
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}

unsigned int fib_unint(int n)
{
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    unsigned int a=0,b=1,c;
    for(int i=2;i<=n;i++)
    {
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}

unsigned long fib_unlong(int n)
{
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    unsigned long a=0,b=1,c;
    for(int i=2;i<=n;i++)
    {
        c=a+b;
        a=b;
        b=c;
    }
    return c;
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
}
