#include <stdio.h>
#include <stdlib.h>
#define SIZE 8

/*3.59
���Ƶ�һ����ѧ���ʽ����xh��yhΪ�з�������xl��ylΪ�޷�������
��x=xh*2^64+xl,y=yh*2^64+yl,��x*y=xh*yh*2^128+(xh*yl+xl*yh)*2^64+xl*yl
ȥ����������ʵ���ϲ�����������������x*y=(xh*yl+xl*yh)*2^64+xl*yl
Ҳ����˵��Ҫ�����xh*yl��xl*yh�ӵ�xl*yl�ĸ�64λ�����
��������ϸ����Ĵ������ע�⣺
movq %rdx,%rax    //%rdxΪx����x����%rax
cqto           //%rdx������Ϊx�ķ���λ��չ,������%rdx��xh,%rax��xl
movq %rsi,%rcx    //%rsiΪy����y���͸�%rcx
sarq $63,%rcx    //ͨ����������ʵ��y�ķ�����չ����%rcxΪyh,%rsi��yl
imulq %rax,%rcx    //%rcx=yh*xl
imulq %rsi,%rdx    //%rdx=xh*yl
addq %rdx,%rcx    //%rcx=yh*xl+xh*yl
mulq %rsi            //��������64λ�޷�������ȫ128λ�˻����õ�%raxΪ��64λ�����%rdxΪ��64λ��λ���
addq %rcx,%rdx    //%rdx�н�λ��ֵ����֮ǰ����õ���������λ���%rcx���õ����յĸ�64λ���
movq %rax,(%rdi)    //��64λ�������dest
movq %rdx,8(%rdi)    //��64λ�������dest+8��ʼ��ַ��С�˻�����
ret  //����������
*/

/*3.61*/
long cread_alt(long *xp)
{
    int x=0;
    int *p=xp?xp:&x;
    return *p;
}

/*3.63*/
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

/*3.65
A.%rdx
B.%rax
C.15
*/

/*3.67���word�ĵ�*/

/*3.69
A.CNT=7
B.typedef struct
   {
        long idx;
        long x[4];
    }a_struct;
    */

    /*3.71*/
    void good_echo()
{
    char buf[SIZE];
    int i;
    while (1)
    {
        if (!fgets(buf, SIZE, stdin))
            return;
        for (i = 0; buf[i] && buf[i] !='\n'; i++)
        {
            if( putchar(buf[i]) == EOF)
                return;
        }
        if (buf[i] =='\n')
        {
            putchar('\n');
            return;
        }
    }
}

int main()
{
    printf("Hello 1190201421 ����\n");
    return 0;
}
