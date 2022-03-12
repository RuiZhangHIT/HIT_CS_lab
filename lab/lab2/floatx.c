#include <stdio.h>
#include <stdlib.h>

typedef union u
//考虑到int和float均为32位，下列代码利用共用体实现浮点数的位表示
{
	int x;
	float y;
}u;

u u1,u2,u3,u4,u5,u6,u7;

int main()
{
	u1.x=0x0;
	u2.x=0x80000000;
	u3.x=0x1;
	u4.x=0x7F7FFFFF;
	u5.x=0x800000;
	u6.x=0x7F800000;
	u7.x=0x7FFFFFFF;
	printf("+0的十进制为%f,十六进制为%08x\n",u1.y,u1.x);
	printf("-0的十进制为%f,十六进制为%08x\n",u2.y,u2.x);
	printf("最小浮点正数的十进制为%.64f,十六进制为%08x\n",u3.y,u3.x);
	printf("最大浮点正数的十进制为%f,十六进制为%08x\n",u4.y,u4.x);
	printf("最小正的规格化浮点数的十进制为%.64f,十六进制为%08x\n",u5.y,u5.x);
	printf("正无穷大的十进制为%f,十六进制为%08x\n",u6.y,u6.x);
	printf("NaN的十进制为%f,十六进制为%08x\n",u7.y,u7.x);
}
