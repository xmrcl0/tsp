/*
 * AGA511
 * EP-2
 * tsp.c
 * Purpose: Traveling Salesman Problem
 *
 * @author: Marcelo Pinto
 * @email: mpinto@usp.br
 * @version: 0.5
 * @date: 09/09/2017
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include "randperm.h"
#include "print.h"
#include "utils.h"

/*
 * Create euclidian distance matrix
 */
void
distance_matrix(float v[][2], float d[][4])
{
    int i, j;

    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            d[i][j] = sqrt(pow(v[i][0] - v[j][0], 2) + pow(v[i][1] - v[j][1], 2));
}


/*
 * Create a hamiltonian cycle aka "path"
 */
void
create_path(int n, int v[])
{
    randperm(n , v);
    v[n] = v[0];
}


/*
 * Measure the path length
 */
float
measure_path(float d[][4], int p[])
{
    int i;
    float l = 0;

    for (i = 0; i < 4; i++)
        l = l + d[p[i]][p[i+1]]; 
    return l;
}


int
main(int argc, char **argv)
{
    int i, j, n;
    float c[4][2] = {0};
    float d[4][4] = {0};
    int p[5] = {0}, min_p[5] = {0};
    float l = 0, min_l = FLT_MAX;
    FILE *file;

    // Print number of paths
    printf("\nnumber of cities = %d\n", 4);
    printf("possible paths = (%d - 1)! / 2 = %d\n\n", 4, 3);

    // Read cities coordinate file
    file = fopen("data/grid04_xy.txt", "r");
    for (i = 0; i < 4; i++)
        for(j = 0; j < 2; j++)
            if(!fscanf(file, "%f", &c[i][j]))
                break;
    fclose(file);

    // Print cities coordinates
    print_cord(c);

    // Create a new seed
    srand(time(NULL));

    // Create distance matrix
    distance_matrix(c, d);
    print_dist(d);

    // Simulates n trips
    printf ("Possible Paths:\n");
    for (n = 0; n < atoi(argv[1]); n++)
    {
        create_path(4, p);
        l = measure_path(d, p);
        print_path(d, p, l, atoi(argv[2]));
        if (l < min_l)
            min_l = l;
            array_copy(p, min_p, 5);
    }

    // Print minimal path found
    printf ("\nMinimal path found:\n");
    print_path(d, min_p, min_l, atoi(argv[2]));

    return 0;
}
