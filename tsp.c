/*
 * AGA511
 * EP-2
 * tsp.c
 * Purpose: Traveling Salesman Problem
 *
 * @author: Marcelo Pinto
 * @email: mpinto@usp.br
 * @version: 0.2
 * @date: 09/09/2017
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <stddef.h>
#include "randperm.h"
#include "print.h"
#include "utils.h"

/*
 * Create euclidian distance matrix
 */
void
distance_matrix(float ***v, float ***d, int n)
{
    int i, j, nrows, ncols;

    ncols = n;
    nrows = n;

    *d =  (float **)malloc(nrows * sizeof(float *));
    for (i = 0; i < nrows; i++)
        (*d)[i] = (float *)malloc(ncols * sizeof(float));

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            (*d)[i][j] = sqrt(pow((*v)[i][0] - (*v)[j][0], 2) + pow((*v)[i][1] - (*v)[j][1], 2));
}


/*
 * Create a hamiltonian cycle aka "path"
 */
void
create_path(int n, int **v)
{
    int i;

    (*v) =  (int *) malloc((n + 1) * sizeof(int));

    randperm(n, *v);
    (*v)[n] = (*v)[0];
}


/*
 * Measure the path length
 */
float
measure_path(float ***d, int n, int **p)
{
    int i;
    float l = 0;

    for (i = 0; i < n; i++)
        l = l + (*d)[(*p)[i]][(*p)[i+1]];
    return l;
}


/*
 * Read cities coordinate file
 */
int
read_file(char *file, float ***array)
{
    int i, j, nrows = 0, ncols = 2;
    char c;
    FILE *f;

    f = fopen(file, "r");
    while(!feof(f))
    {
        c = fgetc(f);
        if (c == '\n')
            nrows++;
    }

    *array =  (float **)malloc(nrows * sizeof(float *));
    for (i = 0; i < nrows; i++)
        (*array)[i] = (float *) malloc(ncols * sizeof(float));

    f = fopen(file, "r");
    for (i = 0; i < nrows; i++)
        for(j = 0; j < ncols; j++)
            if(!fscanf(f, "%f", &(*array)[i][j]))
                break;
    fclose(f);
    return nrows;
}


/*
 * Main routine
 */
int
main(int argc, char **argv)
{
    int i, j, n;
    long double ii;
    float **c, **d;
    int *p, *min_p;   
    float l = 0, min_l = FLT_MAX;
    FILE *file;

    //Read file
    n = read_file(argv[3], &c);

    // Create a new seed
    srand(time(NULL));

    // Create distance matrix
    distance_matrix(&c, &d, n);

    // Simulates n round trips
    printf ("Possible Paths:\n");
    for (ii = 0; ii < strtold(argv[1], NULL); ii++)
    {
        create_path(n, &p);
        l = measure_path(&d, n, &p);
        print_path(&d, &p, n, l, atoi(argv[2]));

        if (l < min_l)
        {
            min_l = l;
            array_copy(&p, &min_p, n);
        }
        free(p);
    }

    // Print report 

    // Print number of paths
    printf("\n\n\nResults:\n");
    printf("\nnumber of cities = %d\n", n);
    printf("possible paths   = %.0Lf\n", factorial(n - 1) / 2);
    printf("simulated paths  = %s\n", argv[1]);

    // Print cities coordinates
    print_cord(&c, n);

    // Print distance matrix
    print_dist(&d, n);

    // Print minimal path found
    printf ("Minimal path found:\n");
    print_path(&d, &min_p, n,  min_l, atoi(argv[2]));
    printf("\n");

    free(min_p);
    free(c);
    free(d);

    return 0;
}
