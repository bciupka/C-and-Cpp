#include <stdio.h>
#include <stdlib.h>
void print(char *c)
{
    while(*(c) != '\0')
    {
        printf("%c\n",*c);
        c++;
    }
}
int main()
{
    char c[8] = "John";
    print(c);
    return 0;
}
