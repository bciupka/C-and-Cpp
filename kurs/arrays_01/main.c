#include <stdio.h>
#include <stdlib.h>
void suma(int *A, int size)
{
    int i;
    int sum = 0;
    for(i=0; i < size; i++)
    {
        sum=sum+*(A+i);
    }
    return sum;
}
int main()
{
    int A[]={1, 2, 3, 4, 5};
    printf("size of A %d\n", sizeof(A));
    printf("single val of A %d\n", sizeof(A[0]));

    int size = sizeof(A)/sizeof(A[0]);
    printf("size = %d\n", size);

    //int i, sum=0;
    //for(i=0; i < size; i++)
    //{
    //   sum=sum+A[i];
    //}
    int sumka;
    sumka = suma(A, size);


    //printf("suma elementow wynosi %d\n", sum);
    return 0;
}
