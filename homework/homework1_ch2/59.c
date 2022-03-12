#include <stdio.h>
#include <stdlib.h>

int cal(int x,int y)
{
    printf("运算结果为：0x%08x\n",(x&0xFF)|(y&0xFFFFFF00));
}

int main()
{
    int x,y;
    printf("请以十六进制形式输入两个整型数\n");
    scanf("%x%x",&x,&y);
    cal(x,y);
    return 0;
}
