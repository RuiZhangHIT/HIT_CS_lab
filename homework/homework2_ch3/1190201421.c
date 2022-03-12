#include <stdio.h>
#include <stdlib.h>
#define SIZE 8

/*3.59
先推导一个数学表达式：（xh和yh为有符号数，xl和yl为无符号数）
若x=xh*2^64+xl,y=yh*2^64+yl,则x*y=xh*yh*2^128+(xh*yl+xl*yh)*2^64+xl*yl
去除会溢出的项（实际上不会产生溢出），则有x*y=(xh*yl+xl*yh)*2^64+xl*yl
也就是说需要算出来xh*yl和xl*yh加到xl*yl的高64位结果上
下面对书上给出的代码进行注解：
movq %rdx,%rax    //%rdx为x，将x传给%rax
cqto           //%rdx被设置为x的符号位扩展,即现在%rdx是xh,%rax是xl
movq %rsi,%rcx    //%rsi为y，将y传送给%rcx
sarq $63,%rcx    //通过算术右移实现y的符号扩展，即%rcx为yh,%rsi是yl
imulq %rax,%rcx    //%rcx=yh*xl
imulq %rsi,%rdx    //%rdx=xh*yl
addq %rdx,%rcx    //%rcx=yh*xl+xh*yl
mulq %rsi            //计算两个64位无符号数的全128位乘积，得到%rax为低64位结果，%rdx为高64位进位结果
addq %rcx,%rdx    //%rdx中进位的值加上之前计算得到的两个高位结果%rcx，得到最终的高64位结果
movq %rax,(%rdi)    //低64位结果赋给dest
movq %rdx,8(%rdi)    //高64位结果赋给dest+8开始地址（小端机器）
ret  //结束，返回
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

/*3.67详见word文档*/

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
    printf("Hello 1190201421 张瑞\n");
    return 0;
}
