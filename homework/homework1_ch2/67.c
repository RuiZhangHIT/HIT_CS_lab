#include <stdio.h>
#include <stdlib.h>

/*A.����λ��k���ڵ��ڴ���λֵ��λ��wʱ���ܶ������ʵ��λ������k mod w����������Ϊ��û�б��ϵģ�Ӧ����������λ��С�ڴ���λֵ��λ����
B.��int_size_is_32_32()
C.��int_size_is_32_16()*/

int int_size_is_32_32()
{
    int set_msb=1<<31;
    int beyond_msb=1<<31<<1;
    return set_msb&&!beyond_msb;
}

int int_size_is_32_16()
{
    int set_msb=1<<15<<15<<1;
    int beyond_msb=1<<15<<15<<2;
    return set_msb&&!beyond_msb;
}

int main()
{
    printf("%d\n",int_size_is_32_32());
    printf("%d\n",int_size_is_32_16());
    return 0;
}
