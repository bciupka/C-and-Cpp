#include <stdio.h>
#include <stdlib.h>

void SumAndProduct(int *table, int size)
{
    int sum = 0;
    int multi = 1;
    for(int i = 0; i<size; ++i)
    {
        sum += *(table + i);
        multi *= *(table + i);
    }
    printf("Sum is %d, product is %d\n", sum, multi);
}

int main()
{
    int A[] = {1, 8, 4, 6, 9};
    printf("Size of A in bytes: %d\n", sizeof(A));
    int size = sizeof(A)/sizeof(*(A));
    printf("Size of A: %d\n\n", size);
    SumAndProduct(A, size);
    return 0;
}
