#include <stdio.h>
#include <stdlib.h>

int mul3div4(int x)
{
    /*�˷��������*/
    x+=x<<1;
   /*�������Ϊ��������������ֵ������ֱ���������룬����������ֵ�������룬�ټ��ϸ���*/
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
