#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    a=1025;
    int *p;
    p=&a;
    printf("Value of a = %d\n", a);
    printf("Address of p equals %d\n", p);
    printf("Value of *p equals %d\n", *p);

    printf("Address of p+1 equals %d\n", p+1);
    printf("Value of *p+1 equals %d\n", *(p+1));

    char *p0;
    p0=(char*)p;
    printf("Address of p0 equals %d\n", p0);
    printf("Value under *p0 %d\n", *p0);

    printf("Address of p0+1 equals %d\n", (p0+1));
    printf("Value under *p0+1 %d\n", *(p0+1));
    printf("Address of p0+2 equals %d\n", (p0+2));
    printf("Value under *p0+2 %d\n", *(p0+2));
    printf("Address of p0+3 equals %d\n", (p0+3));
    printf("Value under *p0+3 %d\n", *(p0+3));
    printf("Address of p0+4 equals %d\n", (p0+4));
    printf("Value under *p0+4 %d\n", *(p0+4));
    return 0;
}
