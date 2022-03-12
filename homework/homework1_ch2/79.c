#include <stdio.h>
#include <stdlib.h>

int mul3div4(int x)
{
    /*乘法会有溢出*/
    x+=x<<1;
   /*除法结果为四舍五入后的整数值：正数直接四舍五入，负数按绝对值四舍五入，再加上负号*/
   if(x>0)
        return (x+(1<<1))>>2;
    else
        return (x+1)>>2;
}

int main()
{
    printf("%d\n",mul3div4(-2));
    printf("%d\n",mul3div4(1));
    return 0;
}
