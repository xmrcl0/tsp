/** @file tsp.c
 *  @brief Traveling Salesman Problem.
 *
 *  @author Marcelo Pinto
 *  @email mpinto@usp.br
 *  @version 0.2
 *  @date 09/11/2017
 *  @bug No known bugs
 */


#include "tsp.h"
#include "print.h"
#include "utils.h"


void
help (void)
{
  printf ("usage: tsp [-h] [-n <ITER>] -m <MODE> -f <FILE>\n");
  printf ("Find best path to Traveling Salesman Problem using Monte Carlo Method\n\n");
  printf ("Options:\n");
  printf ("  -n <ITER>    Number of paths to simulate\n");
  printf ("  -m <MODE>    Exibition mode 0 1 or 2\n");
  printf ("  -f <FILE>    Cities coorinates file\n");
  printf ("  -h           Show this help message and exit\n\n");
  printf ("Example:\n");
  printf ("  tsp -n 5 -m 0 -f data/grid04_xy.txt   # Simulates 5 paths for 4 cities data file\n");
}


void
distance_matrix (float ***v, float ***d, int n)
{
  int i, j, nrows, ncols;

  ncols = n;
  nrows = n;

  *d = (float **) malloc (nrows * sizeof (float *));
  for (i = 0; i < nrows; i++)
    (*d)[i] = (float *) malloc (ncols * sizeof (float));

  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      (*d)[i][j] = sqrt (pow ((*v)[i][0] - (*v)[j][0], 2) + pow ((*v)[i][1] - (*v)[j][1], 2));
}


void
create_path (int n, int **v)
{
  int i;

  (*v) = (int *) malloc ((n + 1) * sizeof (int));

  randperm (n, *v);
  (*v)[n] = (*v)[0];
}


float
measure_path (float ***d, int n, int **p)
{
  int i;
  float l = 0;

  for (i = 0; i < n; i++)
    l = l + (*d)[(*p)[i]][(*p)[i + 1]];
  return l;
}


int
read_file (char *file, float ***array)
{
  int i, j, nrows = 0, ncols = 2;
  char c;
  FILE *fp;

  // Get the number of cities from coordinates file 
  fp = fopen (file, "r");
  if (fp == NULL)
  {
    perror ("Error");
    exit (EXIT_FAILURE);
  }

  while (!feof (fp))
  {
    c = fgetc (fp);
    if (c == '\n')
      nrows++;
  }

  // Allocate memory for coordinates matrix 
  *array = (float **) malloc (nrows * sizeof (float *));
  for (i = 0; i < nrows; i++)
    (*array)[i] = (float *) malloc (ncols * sizeof (float));

  // Read coordinates from file to coordinates matrix
  fseek (fp, 0, SEEK_SET);
  for (i = 0; i < nrows; i++)
    for (j = 0; j < ncols; j++)
      if (!fscanf (fp, "%f", &(*array)[i][j]))
	break;
  fclose (fp);
  return nrows;
}


/*
 * Main routine
 */
int
main (int argc, char **argv)
{
  char c;
  long double i, num_iter;
  int num_cities, nflag = 0, mflag = 0, fflag = 0, mode;
  float **coord, **distance;
  int *path, *min_path;
  float len = 0, min_len = FLT_MAX;
  FILE *file;


  // Read and parse command line arguments
  opterr = 0;
  while ((c = getopt (argc, argv, "n:m:f:h::")) != -1)
    switch (c)
    {
    case 'n':
      nflag = 1;
      if (!is_integer (optarg))
      {
	      fprintf (stderr, "%s: error: number of simulations must be an integer\n", argv[0]);
	      exit (EXIT_FAILURE);
      }
      else
	      num_iter = strtold (optarg, NULL);
      break;
    case 'm':
      mflag = 1;
      if (!is_positive_number (optarg))
      {
	      fprintf (stderr, "%s: error: invalid mode, choose 0, 1 or 2\n", argv[0]);
	      exit (EXIT_FAILURE);
      }
      else
	      mode = atoi (optarg);
      if (mode > 2)
      {
	      fprintf (stderr, "%s: error: invalid mode, choose 0, 1 or 2\n", argv[0]);
	      exit (EXIT_FAILURE);
      }
      break;
    case 'f':
      fflag = 1;
      num_cities = read_file (optarg, &coord);
      break;
    case 'h':
      help ();
      exit (EXIT_SUCCESS);
      break;
    case '?':
      fprintf (stderr, "%s: error: invalid option\n", argv[0]);
      return 1;
    default:
      fprintf (stderr, "usage: tsp [-h] [-n <ITER>] -m <MODE> -f <FILE>\n");
      abort ();
    }

  for (i = optind; i < argc; i++)
  {
    fprintf (stderr, "%s: error: too many or too few arguments\n", argv[0]);
    exit (EXIT_FAILURE);
  }

  if (num_iter + 1 < num_iter)
  {
    fprintf (stderr, "%s: error: number of simulations must be less than %Lf \n", argv[0], LDBL_MAX);
    exit (EXIT_FAILURE);
  }

  // Check if obrigatory argumets were given
  if (nflag == 0 || mflag == 0 || fflag == 0)
  {
    fprintf (stderr, "%s: error: too few parameters\n", argv[0]);
    fprintf (stderr, "usage: tsp [-h] [-n <ITER>] -m <MODE> -f <FILE>\n");
    exit (EXIT_FAILURE);
  }

  // Create a new seed
  srand (time (NULL));

  // Create distance matrix
  distance_matrix (&coord, &distance, num_cities);

  // Simulates n round trips
  printf ("Possible Paths:\n");
  for (i = 0; i < num_iter; i++)
  {
    create_path (num_cities, &path);
    len = measure_path (&distance, num_cities, &path);
    print_path (&distance, &path, num_cities, len, mode);

    if (len < min_len)
    {
      min_len = len;
      array_copy (&path, &min_path, num_cities);
    }
    free (path);
  }

  // Print report 
  print_repo (coord, distance, min_path, num_cities, min_len, num_iter, mode);

  free (min_path);
  free (coord);
  free (distance);

  return 0;
}
