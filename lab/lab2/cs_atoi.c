#include <stdio.h>
#include <stdlib.h>

int cs_atoi(char s[])
{
	int n=0,len=strlen(s);
	for (int i=0; i<len; i++)
	{
		if(i!=0||s[0]!='+')
        {
            n=10*n+(s[i]-'0');
        }
	}
	return n;
}

int main()
{
	printf("%d\n", cs_atoi("123456"));
	printf("%d\n", cs_atoi("+456789"));

	printf("请输入需要转化为正数的字符串\n");
	char s[100];
	scanf("%s",s);
	printf("%d", cs_atoi(s));
	return 0;
}
