#include <stdio.h>
#include <stdlib.h>
#include<math.h>

char* cs_itoa(int x, char* s)
{
    int n;
    for(n=0;pow(10,n)<=x;n++)
    {
        ;
    }
    for(int i=0;i<n;i++)
    {
        s[i]=(x/(int)pow(10,n-i-1))%10+'0';
    }
    s[n]='\0';
    return s;
}

int main()
{
    char s[100];
    printf("%s\n",cs_itoa(+2021,s));
    printf("%s\n",cs_itoa(11902014,s));

    printf("请输入需要转化为字符串的正数\n");
    int x;
    scanf("%d",&x);
    printf("%s\n",cs_itoa(x,s));
    return 0;
}
