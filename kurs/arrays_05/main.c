#include <stdio.h>
#include <stdlib.h>



void print(int (*b)[3])
{
    int i, j;
    for(i=0; i<2; i++)
    {
        for(j=0; j<3; j++)
        {
            printf("B[%d][%d] = %d\t", i, j, b[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int B[2][3]={{2,3,6},{4,5,8}};
    int (*p)[3] = B;

    print(B);

    printf("Address for the first array B[0] = %d\n", B[0]);
    printf("Address for the second array B[0] = %d\n", B[1]);

    printf("Address for the first array B[0] = %d\n", p);
    printf("Address for the second array B[0] = %d\n", p+1);




    return 0;
}
