#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c[8];
    //char c[8] = "John";
    char *p;
    p=c;
    c[0]='J';
    c[1]='o';
    c[2]='h';
    c[3]='n';
    c[4]='\0';


    printf("%s\n", c);

    int len = 0;
    while(c[len] != '\0')
    {
        len++;
    }
    printf("Liczba znakow = %d\n", len);
    int len1 = strlen(c);
    printf("%d\n", len1);
    return 0;
}
