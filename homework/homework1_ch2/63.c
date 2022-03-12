#include <stdio.h>
#include <stdlib.h>
int w=8*sizeof(int);

void printBinary(int x)
/*打印二进制表达式*/
{
    char num[32];
    unsigned n=1<<(w-1);
    for (int i=0;i<w;i++)
    {
        num[i]=((x&n)==0)?'0':'1';
        n>>=1;
    }
    printf("二进制表达式为：%s\n",num);
}

unsigned srl(unsigned x,int k)
/*用算术右移完成逻辑右移*/
{
    unsigned xsra=(int)x>>k;
    unsigned a=-1;
    if(k!=0)
        a=~(a<<(w-k));
    xsra=a&xsra;
    return xsra;
}

int sra(int x,int k)
/*用逻辑右移完成算术右移*/
{
    int xsrl=(unsigned)x>>k;
    /*获取符号位*/
    unsigned m=1<<(w-1);
    m=(x&m)>>(w-1);

    unsigned a=-m;
    if(k==0)
        a=0;
    else
        a=a<<(w-k);
    xsrl=a|xsrl;
    return xsrl;
}

int main()
{
    printBinary(srl(90,0));
    printBinary(srl(-157,5));
    printBinary(sra(-90,3));
    printBinary(sra(4421,31));
    return 0;
}
