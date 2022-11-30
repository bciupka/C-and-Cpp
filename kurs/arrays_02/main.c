#include <stdio.h>
#include <stdlib.h>
/*
int Double(int a[], int s)
{
    int i, sum=0;
    for(i=0; i<s; i++)
    {
        a[i] = 2*a[i];
        sum+=a[i];
    }
    return sum;
}
*/

int Double(int *a, int s)
{
    int i, sum=0;
    for(i=0; i<s; i++)
    {
        *(a+i) = 2* *(a+i);
        sum+=*(a+i);
    }
    return sum;
}

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    int size = sizeof(A)/sizeof(A[0]);
    int suma = Double(A, size);
    int i;
    for(i=0; i<size; i++)
    {
        printf("Doubled value of element array A[%d] = %d\n", i, A[i]);
    }
    printf("Sum of elements of array A equals %d\n", suma);
    for(i=0; i<size; i++)
    {
        printf("Address of elements of array A+%d = %d\n", i, A+i);
    }
    return 0;
}
