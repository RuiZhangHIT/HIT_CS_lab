#include <stdio.h>
#include <stdlib.h>
#include<math.h>

char* cs_ftoa(float x, char* s)
{
    int num1;
    if(x<0)
    {
        s[0]='-';
        x=-x;
    }
    else
    {
        s[0]='+';
    }

    for(num1=0;pow(10,num1)<=x;num1++)
    {
        ;
    }
    for(int i=1;i<=num1;i++)
    {
        s[i]=(int)(x/(int)pow(10,num1-i))%10+'0';
        x=x-(float)((int)(x/(int)pow(10,num1-i))%10)*(float)pow(10,num1-i);
    }
    if(num1==0)
    {
        num1=1;
        s[num1]='0';
    }
    if(x==0)
    {
        s[num1+1]='\0';
        if(s[0]=='+')
            return &s[1];
        else
            return s;
    }

    s[num1+1]='.';
    int num2=1 ;
    while(x>0)
    {
        s[num1+1+num2]='0'+(int)(x*10);
        x=x*10-(float)((int)(x*10));
        num2++;
    }
    s[num1+1+num2]='\0';
    if(s[0]=='+')
            return &s[1];
        else
            return s;
}

int main()
{
    char s[100];
    float x;
    printf("%f以字符串形式输出为%s\n",+21.125,cs_ftoa(+21.125,s));
    printf("%f以字符串形式输出为%s\n",-0.1,cs_ftoa(-0.1,s));

    printf("请输入需要转化为字符串的浮点数\n");
    scanf("%f",&x);
    printf("%f以字符串形式输出为%s\n",x,cs_ftoa(x,s));
    return 0;
}
