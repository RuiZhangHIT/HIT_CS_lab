#include <stdio.h>
#include <stdlib.h>
int w=8*sizeof(int);

void printBinary(int x)
/*��ӡ�����Ʊ��ʽ*/
{
    char num[32];
    unsigned n=1<<(w-1);
    for (int i=0;i<w;i++)
    {
        num[i]=((x&n)==0)?'0':'1';
        n>>=1;
    }
    printf("�����Ʊ��ʽΪ��%s\n",num);
}

unsigned srl(unsigned x,int k)
/*��������������߼�����*/
{
    unsigned xsra=(int)x>>k;
    unsigned a=-1;
    if(k!=0)
        a=~(a<<(w-k));
    xsra=a&xsra;
    return xsra;
}

int sra(int x,int k)
/*���߼����������������*/
{
    int xsrl=(unsigned)x>>k;
    /*��ȡ����λ*/
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
