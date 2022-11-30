#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    a=1025;

    int *p;
    p=&a;

    int **q;
    q=&p;

    int ***r;
    r=&q;

    printf("Val of a %d\n", a);
    printf("Addr of p %d\n", p);
    printf("Addr of q %d\n", q);
    printf("Addr of r %d\n", r);
    printf("Val of **q %d\n", **q);
    printf("Val of ***r %d\n", ***r);


    **q=**q+2;
    printf("%d\n", **q);

    return 0;
}
