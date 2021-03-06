/** @file     tsp.h
 *  @brief    Function prototypes for tsp.
 *  @author   Marcelo Pinto (xmrcl0@gmail.com)
 *  @date     09/12/2017
 */

#define _GNU_SOURCE

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <stddef.h>
#include <unistd.h>

/** @brief Print command help.
 *
 *  @param  void
 *  @return void 
 */
void help (void);


/** @brief Create euclidian distance matrix
 *
 *  @param[in]  c Coordinates matrix
 *  @param[out] d Distance matrix
 *  @param[in]  n Number of cities 
 *  @return void
 */
void distance_matrix (float ***c, float ***d, int n);


/** @brief Create a hamiltonian cycle aka "path"
 *
 *  @param[in]  n Number of cities 
 *  @param[out] p Path array
 *  @return void
 */
void create_path (int n, int **p);


/** @brief Measure the path length
 *
 *  @param[in] d Distance matrix
 *  @param[in] n Number of cities 
 *  @param[in] p Path array
 *  @return Path length 
 */
float measure_path (float ***d, int n, int **p);


/** Read cities coordinate file
 *
 *  @param[in]  f Cities coordinate file
 *  @param[out] v Coordinates matrix 
 *  @return Number of cities
 *
 *  @retval  n Number of cities
 *  @retval  0 File not found 
 *  @retval -1 Invalid file 
 */
int read_file (char *f, float ***m);
