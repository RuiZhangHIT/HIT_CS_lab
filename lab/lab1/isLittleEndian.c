#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=0x12345678;
    char *p=(char *)&a;

    if(*p==0x78)
        printf("本机为小端模式\n");
    else
        printf("本机为大端模式\n");

    return 0;
}

