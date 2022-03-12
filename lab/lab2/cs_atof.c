#include <stdio.h>
#include <stdlib.h>
#include<math.h>

float cs_atof(char s[])
{
	int len=strlen(s),x;
	float n=0,sign;

	for (int i=0;i<len;i++)
	{
	    if(s[0]=='-')
        {
            sign=-1;
        }
        else
        {
            sign=1;
        }
		if (s[i]=='.')
		{
			x=i;
			continue;
		}
		if(i!=0||(s[0]!='+'&&s[0]!='-'))
        {
            n=n*10+s[i]-'0';
        }
	}

	n=sign*n*pow(10, (x-len+1));
	return n;
}

int main()
{
	printf("%f\n", cs_atof("3.14"));
	printf("%f\n",cs_atof("-3.14"));
	printf("%f\n", cs_atof("+3.14"));
	printf("%f\n", cs_atof("0"));

	printf("请输入需要转化为浮点数的字符串\n");
	char s[100];
	scanf("%s",s);
	printf("%f\n", cs_atof(s));
	return 0;
}
