#include <stdio.h>
#include <stdlib.h>
#define SIZE 8

void good_echo()
{
    char buf[SIZE];
    int i;
    while (1)
    {
        if (!fgets(buf, SIZE, stdin))
            return;
        for (i = 0; buf[i] && buf[i] !='\n'; i++)
        {
            if( putchar(buf[i]) == EOF)
                return;
        }
        if (buf[i] =='\n')
        {
            putchar('\n');
            return;
        }
    }
}

int main()
{
    printf("Hello world!\n");
    good_echo();
    return 0;
}
