#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Wczytanie danych z pliku
    FILE *file;
    if ((file = fopen("Data.txt", "r")) == NULL)
    {
        printf("File open error \n");
        exit(1);
    }

    float vals[21][2];
    float a[21][2];
    printf("Date from the file: \n ");

    for (int i=0; i<21; i++)
    {
        fscanf(file, "%f %f", &vals[i][0], &vals[i][1]);
        printf("%.1f\t %.1f\n" , vals[i][0], vals[i][1]);
        a[i][0] = vals[i][0];
        a[i][1] = vals[i][1];
    }
    fclose(file);

    //Obliczenia
    int i;
    float d, A=0, Sx=0, Sy=0, Ix=0, Iy=0, Ixy=0;

    printf("\nThe results:\n");

    for (i=0; i<20; i++)
    {
        d = a[i][0] * a[i+1][1] - a[i+1][0] * a[i][1];
        A += d/2;

        Sx += d * (a[i][1] + a[i+1][1]) / 6;
        Sy += d * (a[i][0] + a[i+1][0]) / 6;

        Ix += d * (a[i][1] * a[i][1] + a[i][1] * a[i+1][1] + a[i+1][1] * a[i+1][1]) / 12;
        Iy += d * (a[i][0] * a[i][0] + a[i][0] * a[i+1][0] + a[i+1][0] * a[i+1][0]) / 12;
        Ixy += d * (a[i][0] * (2 * a[i][1] + a[i][1]) + a[i+1][0] * (a[i][1] + 2 * a[i+1][1])) / 24;

    }
    printf("The area is equal to %.1f\n", A);
    printf("The first moment of area with respect to x axis is equal to %.1f\n", Sx);
    printf("The first moment of area with respect to y axis is equal to %.1f\n", Sy);
    printf("The second moment of area with respect to x axis is equal to %.1f\n", Ix);
    printf("The second moment of area with respect to y axis is equal to %.1f\n", Iy);
    printf("The second moment of area with respect to xy axis is equal to %.1f\n", Ixy);
    return 0;
}
