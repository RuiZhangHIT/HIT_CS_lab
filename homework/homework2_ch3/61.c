#include <stdio.h>
#include <stdlib.h>

long cread_alt(long *xp)
{
    int x=0;
    int *p=xp?xp:&x;
    return *p;
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
