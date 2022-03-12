#include <stdio.h>
#include <stdlib.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start,size_t len)
{
    size_t i;
    for(i=0;i<len;i++)
         printf("%.2x ",start[i]);
    printf("\n\n");
}

int main()
{
    char c='z';

    int i=1190201421;

    unsigned int j=1190201421;

    short k=1421;

    long l=1190201421;

    float x=3.14;

    double y=3.141592;

    char a[4]="hit";

    void *p=NULL;

    int *q=&i;

    struct date
    {
        int month;
        int day;
    }d;
    d.month=3;
    d.day=18;

    enum Bool
    {
        FALSE,TRUE
    }b;

    union  number
    {
        int a;
        float b;
        short c;
    }num;
    num.a=123;

    printf("main函数的地址：%p\n\n",main);
    printf("printf函数的地址：%p\n\n",printf);
    printf("scanf函数的地址：%p\n\n",scanf);

    printf("类型\t\t变量名\t\t内容\t\t\t地址\t\t\t各字节\n");

    printf("char\t\tc\t\t%c\t\t\t%p\t",c,&c);
    show_bytes((byte_pointer)&c,sizeof(char));

    printf("int\t\ti\t\t%d\t\t%p\t",i,&i);
    show_bytes((byte_pointer)&i,sizeof(int));

    printf("unsigned int\tj\t\t%u\t\t%p\t",j,&j);
    show_bytes((byte_pointer)&j,sizeof(unsigned int));

    printf("short\t\tk\t\t%d\t\t\t%p\t",k,&k);
    show_bytes((byte_pointer)&k,sizeof(short));

    printf("long\t\tl\t\t%ld\t\t%p\t",l,&l);
    show_bytes((byte_pointer)&l,sizeof(long));

    printf("float\t\tx\t\t%f\t\t%p\t",x,&x);
    show_bytes((byte_pointer)&x,sizeof(float));

    printf("double\t\ty\t\t%lf\t\t%p\t",y,&y);
    show_bytes((byte_pointer)&y,sizeof(double));

    printf("数组\t\ta\t\t%s\t\t\t%p\t",a,a);
    show_bytes((byte_pointer)a,sizeof(a));

    printf("void*\t\tp\t\t%p\t%p\t",p,&p);
    show_bytes((byte_pointer)&p,sizeof(void*));

    printf("int*\t\tq\t\t%p\t%p\t",q,&q);
    show_bytes((byte_pointer)&q,sizeof(int*));

    printf("struct\t\td\t\t%d  %d\t\t\t%p\t",d.month,d.day,&d);
    show_bytes((byte_pointer)&d,sizeof(d));

    printf("enum\t\tb\t\t%d  %d\t\t\t%p\t",FALSE,TRUE,&b);
    show_bytes((byte_pointer)&b,sizeof(b));

    printf("union\t\tnum\t\t%d\t\t\t%p\t",num.a,&num);
    show_bytes((byte_pointer)&num,sizeof(num));

    num.b=3.14;
    printf("\t\tnum\t\t%f\t\t%p\t",num.b,&num);
    show_bytes((byte_pointer)&num,sizeof(num));
    num.c=18;
    printf("\t\tnum\t\t%d\t\t\t%p\t",num.c,&num);
    show_bytes((byte_pointer)&num,sizeof(num));

    return 0;
}
