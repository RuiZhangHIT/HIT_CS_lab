#include <stdio.h>
#include <stdlib.h>

typedef union u
//���ǵ�int��float��Ϊ32λ�����д������ù�����ʵ�ָ�������λ��ʾ
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
	printf("+0��ʮ����Ϊ%f,ʮ������Ϊ%08x\n",u1.y,u1.x);
	printf("-0��ʮ����Ϊ%f,ʮ������Ϊ%08x\n",u2.y,u2.x);
	printf("��С����������ʮ����Ϊ%.64f,ʮ������Ϊ%08x\n",u3.y,u3.x);
	printf("��󸡵�������ʮ����Ϊ%f,ʮ������Ϊ%08x\n",u4.y,u4.x);
	printf("��С���Ĺ�񻯸�������ʮ����Ϊ%.64f,ʮ������Ϊ%08x\n",u5.y,u5.x);
	printf("��������ʮ����Ϊ%f,ʮ������Ϊ%08x\n",u6.y,u6.x);
	printf("NaN��ʮ����Ϊ%f,ʮ������Ϊ%08x\n",u7.y,u7.x);
}
