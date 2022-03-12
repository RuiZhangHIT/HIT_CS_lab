#include <stdio.h>
#include <stdlib.h>

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

int main()
{
    printf("%d\n",int_size_is_32_32());
    printf("%d\n",int_size_is_32_16());
    return 0;
}
