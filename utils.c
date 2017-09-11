/** @file utils.c
 *  @brief Utils functions.
 *
 *  @author Marcelo Pinto (xmrcl0@gmail.com)
 *  @bug No known bugs.
 */

#include "utils.h"

int
is_integer (char *number)
{
  int r;
  regex_t regex;
  const char *pattern = "^[0-9]+$";

  r = regcomp (&regex, pattern, REG_EXTENDED);
  if (r)
  {
    fprintf (stderr, "Could not compile regex\n");
    exit (1);
  }

  r = regexec (&regex, number, 0, NULL, 0);
  if (!r)
  {
    return 1;
  }
  return 0;
}


int
is_positive_number (char *number)
{
  int r;
  regex_t regex;
  const char *pattern = "^[0-9]+\\.?([0-9]+)?$";

  r = regcomp (&regex, pattern, REG_EXTENDED);
  if (r)
  {
    fprintf (stderr, "Could not compile regex\n");
    exit (1);
  }

  r = regexec (&regex, number, 0, NULL, 0);
  if (!r)
  {
    return 1;
  }
  return 0;
}


void
array_copy (int **src, int **dst, size_t n)
{
  int i;

  (*dst) = (int *) malloc ((n + 1) * sizeof (int));

  for (i = 0; i <= n; i++)
    (*dst)[i] = (*src)[i];
}


long double
factorial (int n)
{
  int i;
  long double factorial = 1;

  for (i = n; i > 1; i--)
    factorial = factorial * i;
  return factorial;
}


void
randperm (int n, int perm[])
{
  int i, j, t;

  for (i = 0; i < n; i++)
    perm[i] = i;
  for (i = 0; i < n; i++)
  {
    j = rand () % (n - i) + i;
    t = perm[j];
    perm[j] = perm[i];
    perm[i] = t;
  }
}

