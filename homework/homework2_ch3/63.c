#include <stdio.h>
#include <stdlib.h>

long switch_prob(long x, long n)
{
    long result=x;
    switch(n)
    {
        case 60:
        case 62:
            result*=8;
            break;
        case 63:
            result>>=3;
            break;
        case 64:
            result=(result<<4)-result;
        case 65:
            result*=result;
        case 61:
        default:
            result+=0x4b;
    }
    return result;
}

int main()
{
    printf("Hello world!\n");
    printf("%ld\n",switch_prob(20,64));
    return 0;
}
