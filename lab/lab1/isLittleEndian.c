#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=0x12345678;
    char *p=(char *)&a;

    if(*p==0x78)
        printf("����ΪС��ģʽ\n");
    else
        printf("����Ϊ���ģʽ\n");

    return 0;
}

