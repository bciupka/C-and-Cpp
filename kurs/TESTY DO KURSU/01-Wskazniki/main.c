#include <stdio.h>
#include <stdlib.h>

int main()
{
    int var = 258;
    int *point;
    point = &var;

    printf("Var: %d\n\n", var);
    printf("Var add: %d\n", point);
    printf("Point: %d\n", *point);
    printf("Point add: %d\n", &point);
    printf("Var add +1: %d\n\n", point+1);
    char *point2;
    point2 = (char*)point;
    printf("Point char: %d\n", *point2);
    printf("Point+1 char: %d\n", *(point2+1));
    printf("Point+2 char: %d\n", *(point2+2));
    printf("Point+3 char: %d\n", *(point2+3));
    printf("Var char add: %d\n", point2);
    printf("Var char add + 1: %d\n", point2+1);
    printf("Point char add: %d\n", &point2);
    return 0;
}
