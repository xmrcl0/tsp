#include "print.h"

/*
 * Print a path
 */
void
print_path(float d[][4], int p[], float l, int m)
{
    int i;

    if (m == 0)
    {
        for (i = 0; i < 4; i++)
            printf("d[%d][%d]=%.2f, ", p[i], p[i+1], d[p[i]][p[i+1]]);
        printf("distance=%.2f\n", l); 
    }

    else
    if (m == 1)
    {
        for (i = 0; i < 5; i++)
            printf("%d,", p[i]); 
        printf("%.2f\n", l); 
    }

    else
    if (m == 2)
    {
        for (i = 0; i < 5; i++)
            printf("%4d", p[i]);
        printf("\t%4.2f\n", l); 
    }   
}


/*
 * Print distance matrix 
 */
void
print_dist(float d[][4])
{
    int i, j;

    printf("Distance matrix:\n");
    for (i = 0; i < 4; i++)
    {   
        for (j = 0; j < 4; j++)
            printf("%.2f  ", d[i][j]);
        printf("\n");
    }   
    printf("\n");
}

/*
 * Print coordinate matrix 
 */
void
print_cord(float v[][2])
{
    int i, j;

    printf("\nCities coordinates:\n");
    for (i = 0; i < 4; i++)
    {   
        for (j = 0; j < 2; j++)
            printf("%.4f ", v[i][j]); 
        printf("\n");
    }
    printf("\n");
}
