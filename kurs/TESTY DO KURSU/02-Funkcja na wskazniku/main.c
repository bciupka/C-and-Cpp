#include <stdio.h>
#include <stdlib.h>

void Print3Next(int *x)
{
    printf("First %d\n", *x+1);
    printf("Second %d\n", *x+2);
    printf("Third %d\n", *x+3);
    printf("Addres: %d\n\n", x);
}

int main()
{
    int var = 69;
    int *point;
    point = &var;
    Print3Next(point);
    printf("Addres: %d\n", &var);
    return 0;
}
