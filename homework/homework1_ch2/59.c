#include <stdio.h>
#include <stdlib.h>

int cal(int x,int y)
{
    printf("������Ϊ��0x%08x\n",(x&0xFF)|(y&0xFFFFFF00));
}

int main()
{
    int x,y;
    printf("����ʮ��������ʽ��������������\n");
    scanf("%x%x",&x,&y);
    cal(x,y);
    return 0;
}
