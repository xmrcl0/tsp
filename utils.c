#include "utils.h"
#include <regex.h>
#include <stdlib.h>
#include <stdio.h>

/*
 * Verify if a string is a valid integer.
 *
 * @param number
 * @return bool 
*/
int
is_integer(char *number)
{
  int r;
  regex_t regex;
  const char *pattern = "^[0-9]+$";
  
  r = regcomp (&regex, pattern, REG_EXTENDED);
  if (r) {
    fprintf(stderr, "Could not compile regex\n");
    exit(1);
  }
  
  r = regexec (&regex, number, 0, NULL, 0);
  if (!r) {
    return 1;
  }
  return 0;
}



/*
 * Verify if a string is a valid number.
 *
 * @param number
 * @return bool 
*/
int
is_positive_number(char *number)
{
  int r;
  regex_t regex;
  const char *pattern = "^[0-9]+\\.?([0-9]+)?$";

  r = regcomp (&regex, pattern, REG_EXTENDED);
  if (r) {
    fprintf(stderr, "Could not compile regex\n");
    exit(1);
  }

  r = regexec (&regex, number, 0, NULL, 0);
  if (!r) {
    return 1;
  }
  return 0;
}


void
array_copy(int src[], int dst[], size_t n)
{
    int i; 

    for(i = 0; i < n; i++)
    {
        dst[i] = src[i];
    } 
}
