#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
/*为完成调试，构造的书上所说的库函数*/
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

int main()
{
    printf("%08x\n",signed_high_prod(0x80000000,0x00000002));
    printf("%08x\n",unsigned_high_prod(0x80000000,0x0000002));
    printf("%08x\n",unsigned_high_prod(0xf0000000,0x00000002));
    printf("%08x\n",unsigned_high_prod(0x70000000,0x00000002));
    printf("%08x\n",unsigned_high_prod(0xf0000000,0x00000008));
    return 0;
}
