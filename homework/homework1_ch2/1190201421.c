#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

/*2.59*/
int cal(int x,int y)
{
    printf("������Ϊ��0x%08x\n",(x&0xFF)|(y&0xFFFFFF00));
}

/*2.63*/
int w=8*sizeof(int);

unsigned srl(unsigned x,int k)
/*��������������߼�����*/
{
    unsigned xsra=(int)x>>k;
    unsigned a=-1;
    if(k!=0)
        a=~(a<<(w-k));
    xsra=a&xsra;
    return xsra;
}

int sra(int x,int k)
/*���߼����������������*/
{
    int xsrl=(unsigned)x>>k;
    /*��ȡ����λ*/
    unsigned m=1<<(w-1);
    m=(x&m)>>(w-1);

    unsigned a=-m;
    if(k==0)
        a=0;
    else
        a=a<<(w-k);
    xsrl=a|xsrl;
    return xsrl;
}

/*2.67*/
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

/*2.71*/
/*A.�������ڣ�ָ���ֽ�Ϊ����ʱ����չ����δʵ�ַ�����չ��
B.��int xbyte(packed_t word,int bytenum)*/

typedef unsigned packed_t;

int xbyte(packed_t word,int bytenum)
/*ͨ������ȥ����λ�ֽڣ�������������ȥ����λ�ֽڲ�ʵ�ַ�����չ*/
{
    return (int)(word<<((3-bytenum)<<3))>>24;
}

/*2.75*/
/*����Ϊ��ɵ��ԣ������������˵�Ŀ⺯��*/
int signed_high_prod(int x,int y)
{
    int64_t h=(int64_t)x*(int64_t)y;
    return h>>32;
}

unsigned unsigned_high_prod(unsigned x,unsigned y)
{
    int xsign,ysign;
    xsign=x>>31;
    ysign=y>>31;
    return xsign*y+ysign*x+signed_high_prod(x,y);
}

/*2.79*/
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

/*2.83
A.��С��ֵΪx�����ظ�����Ϊy����x��С���������ƶ�kλ��kΪ����y�ĳ��ȣ����õ�x*2^k��
������ȥС�����ֺ�õ�y����ֵY=x*��2^k-1��������С��ΪY/��2^k-1����
B.��������yֵ���󴮵���ֵ��������A�й�ʽ��
(a)101: x=5/7
(b)0110: x=6/15=2/5
(c)010011: x=19/63
*/

/*2.87
����		                              Hex	             M		             E	     V		                         D
-0		                                  8000	        0		                -14	    -0		                         -0.0
��С��>2��ֵ	              4001	        1025/1024	1	        1025*2^��-9��	     2.001953125
512		                                  6000	        1		                9	        512		                         512.0
���ķǹ����	      03ff	            1023/1024	-14	    1023*2^��-24)	     0.0000609755516
������		                          fc00	            ---		            ---	    ������		                ������
ʮ�����Ʊ�ʾΪ3BB0   3BB0	        123/64		    -1	    123*2^��-7��	     0.9609375
*/

int main()
{
    printf("Hello 1190201421 ����\n");
    return 0;
}
