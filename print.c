/** @file print.c
 *  @brief Print functions.
 *
 *  @author Marcelo Pinto (xmrcl0@gmail.com)
 *  @bug No known bugs.
 */

#include "print.h"
#include "utils.h"

void
print_path (float ***distance, int **path, size_t num_city, float len, int mode)
{
  int i;


  if (mode == 0)
  {
    for (i = 0; i < num_city; i++)
      printf ("d[%d][%d]=%.2f, ", (*path)[i], (*path)[i + 1], (*distance)[(*path)[i]][(*path)[i + 1]]);
    printf ("distance=%.2f\n", len);
  }

  else if (mode == 1)
  {
    for (i = 0; i <= num_city; i++)
      printf ("%d,", (*path)[i]);
    printf ("%.2f\n", len);
  }

  else if (mode == 2)
  {
    for (i = 0; i <= num_city; i++)
      printf ("%4d", (*path)[i]);
    printf ("\t%4.2f\n", len);
  }

  // Report specific option
  else if (mode == 3)
  {
    printf ("\nsequence:");
    for (i = 0; i <= num_city; i++)
      printf ("%3d", (*path)[i]);
    printf ("\ndistance: %.2f\n", len);
  }
}


void
print_dist (float ***distance, size_t num_city)
{
  int i, j;

  printf ("Distance matrix:\n");
  for (i = 0; i < num_city; i++)
  {
    for (j = 0; j < num_city; j++)
      printf ("%6.2f", (*distance)[i][j]);
    printf ("\n");
  }
  printf ("\n");
}


void
print_cord (float ***coord, size_t num_city)
{
  int i, j;

  printf ("\nCities coordinates:\n");
  for (i = 0; i < num_city; i++)
  {
    for (j = 0; j < 2; j++)
      printf ("%.4f ", (*coord)[i][j]);
    printf ("\n");
  }
  printf ("\n");
}


void
print_repo (float **coord, float **distance, int *min_path, int num_city, float min_len, long double inter, int mode)
{
  // Print number of paths
  printf ("\n\n\nResults:\n");
  printf ("\nnumber of cities = %d\n", num_city);
  printf ("possible paths   = %.0Lf\n", factorial (num_city - 1) / 2);
  printf ("simulated paths  = %.0Lf\n", inter);

  // Print cities coordinates
  print_cord (&coord, num_city);

  // Print distance matrix
  print_dist (&distance, num_city);

  // Print minimal path found
  printf ("Minimal path found:\n");
  print_path (&distance, &min_path, num_city, min_len, 3);
  printf ("\n");
}
