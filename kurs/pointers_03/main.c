#include <stdio.h>
#include <stdlib.h>

void inc(int *a)
{
    *a = *a + 1;
    printf("local a adr %d\n", a);
    printf("local a %d\n", *a);
}

int main()
{
    int a=5;
    inc(&a);

    printf("global a %d\n", a);
    printf("global a adr %d\n", &a);
    return 0;
}
