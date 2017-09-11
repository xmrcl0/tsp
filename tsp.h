/** @file tsp.h
 *  @brief Function prototypes for tsp.
 *
 *  @author Marcelo Pinto (xmrcl0@gmail.com)
 *  @bug No known bugs.
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <stddef.h>
#include <errno.h>
#include <unistd.h>

/** @brief Print command help.
 *
 *  @param  void
 *  @return void 
 */
void help (void);


/** @brief Create euclidian distance matrix
 *
 * @param coord Coordinates matrix
 * @param distance Distance matrix
 * @param num_city Number of cities 
 * @return Void
 */
void distance_matrix (float ***coord, float ***distance, int num_city);


/** @brief Create a hamiltonian cycle aka "path"
 *
 * @param num_city Number of cities 
 * @param path Path array
 * @return Void
 */
void create_path (int num_city, int **path);


/** @brief Measure the path length
 *
 * @param distance Distance matrix
 * @param num_city Number of cities 
 * @param path Path array
 * @return Float 
 */
float measure_path (float ***distance, int num_city, int **path);


/** Read cities coordinate file
 *
 * @param file Cities file
 * @param array Coordinates array 
 * @return Int
 */
int read_file (char *file, float ***array);
