#include <stdio.h>
#include <stdlib.h>

/*A.�������ڣ�ָ���ֽ�Ϊ����ʱ����չ����δʵ�ַ�����չ��
B.��int xbyte(packed_t word,int bytenum)*/

typedef unsigned packed_t;

int xbyte(packed_t word,int bytenum)
/*ͨ������ȥ����λ�ֽڣ�������������ȥ����λ�ֽڲ�ʵ�ַ�����չ*/
{
    return (int)(word<<((3-bytenum)<<3))>>24;
}

int main()
{
    printf("%08x\n",0x1287ff0a);
    printf("%08x\n",xbyte(0x1287ff0a,0));
    printf("%08x\n",xbyte(0x1287ff0a,1));
    printf("%08x\n",xbyte(0x1287ff0a,2));
    printf("%08x\n",xbyte(0x1287ff0a,3));
    return 0;
}
