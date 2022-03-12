#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

/*2.59*/
int cal(int x,int y)
{
    printf("运算结果为：0x%08x\n",(x&0xFF)|(y&0xFFFFFF00));
}

/*2.63*/
int w=8*sizeof(int);

unsigned srl(unsigned x,int k)
/*用算术右移完成逻辑右移*/
{
    unsigned xsra=(int)x>>k;
    unsigned a=-1;
    if(k!=0)
        a=~(a<<(w-k));
    xsra=a&xsra;
    return xsra;
}

int sra(int x,int k)
/*用逻辑右移完成算术右移*/
{
    int xsrl=(unsigned)x>>k;
    /*获取符号位*/
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
/*A.当移位量k大于等于待移位值的位数w时，很多机器的实际位移量是k mod w，但这种行为是没有保障的，应尽量保持移位量小于待移位值的位数。
B.见int_size_is_32_32()
C.见int_size_is_32_16()*/

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
/*A.错误在于，指定字节为负数时，扩展错误，未实现符号扩展。
B.见int xbyte(packed_t word,int bytenum)*/

typedef unsigned packed_t;

int xbyte(packed_t word,int bytenum)
/*通过左移去掉高位字节，再用算术右移去掉低位字节并实现符号扩展*/
{
    return (int)(word<<((3-bytenum)<<3))>>24;
}

/*2.75*/
/*附上为完成调试，构造的书上所说的库函数*/
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
    /*乘法会有溢出*/
    x+=x<<1;
   /*除法结果为四舍五入后的整数值：正数直接四舍五入，负数按绝对值四舍五入，再加上负号*/
   if(x>0)
        return (x+(1<<1))>>2;
    else
        return (x+1)>>2;
}

/*2.83
A.设小数值为x，其重复序列为y，将x的小数点向右移动k位（k为序列y的长度），得到x*2^k，
做差消去小数部分后得到y的数值Y=x*（2^k-1），即该小数为Y/（2^k-1）。
B.对于下列y值，求串的数值：（代入A中公式）
(a)101: x=5/7
(b)0110: x=6/15=2/5
(c)010011: x=19/63
*/

/*2.87
描述		                              Hex	             M		             E	     V		                         D
-0		                                  8000	        0		                -14	    -0		                         -0.0
最小的>2的值	              4001	        1025/1024	1	        1025*2^（-9）	     2.001953125
512		                                  6000	        1		                9	        512		                         512.0
最大的非规格化数	      03ff	            1023/1024	-14	    1023*2^（-24)	     0.0000609755516
负无穷		                          fc00	            ---		            ---	    负无穷		                负无穷
十六进制表示为3BB0   3BB0	        123/64		    -1	    123*2^（-7）	     0.9609375
*/

int main()
{
    printf("Hello 1190201421 张瑞\n");
    return 0;
}
