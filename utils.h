/** @file utils.h
 *  @brief Function prototypes for utils.
 *
 *  @author Marcelo Pinto (xmrcl0@gmail.com)
 *  @bug No known bugs.
 */

#include <stddef.h>
#include <regex.h>
#include <stdlib.h>
#include <stdio.h>

/** @brief Verify if a string is a valid integer.
 *
 *  @param number Number to be validated
 *  @return Bool
 */
int is_integer(char *number);


/** @brief Verify if a string is a valid number.
 *
 *  @param number Number to be validated
 *  @return Bool 
 */
int is_positive_number(char *number);


/** @brief Copy an array.
 *
 * @param src Source array
 * @param dst Destination array
 * @param n Array size 
 * @return Void
 */
void array_copy(int **src, int **dst, size_t n);


/** @brief Calculates n!.
 *
 * @param n Number
 * @return long double Factorial of n
 */
long double factorial(int n);


/** @brief Permutates an array.
 *
 * Copyright (c) 1990 Michael E. Hohmeyer, hohmeyer@icemcfd.com
 * Permission is granted to modify and re-distribute this code in any manner
 * as long as this notice is preserved.  All standard disclaimers apply.
 *       
 *  @param n Array size
 *  @param perm Array of n elements 
 *  @return Void 
 */
void randperm(int n, int perm[]);
