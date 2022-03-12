#include <stdio.h>
#include <stdlib.h>

/*A.错误在于，指定字节为负数时，扩展错误，未实现符号扩展。
B.见int xbyte(packed_t word,int bytenum)*/

typedef unsigned packed_t;

int xbyte(packed_t word,int bytenum)
/*通过左移去掉高位字节，再用算术右移去掉低位字节并实现符号扩展*/
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
