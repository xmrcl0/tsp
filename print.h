/** @file print.h
 *  @brief Function prototypes for print.
 *
 *  @author Marcelo Pinto (xmrcl0@gmail.com)
 *  @bug No known bugs.
 */

#include <stdio.h>
#include <stdlib.h>

/** @brief Print report.
 *
 *  @param distance Distance matrix 
 *  @param distance Path array 
 *  @param num_city Number of cities 
 *  @param len      Path's length
 *  @param mode     Print mode
 *  @return Void 
 */
void print_path(float ***distance, int **path, size_t num_city, float len, int mode);

/** @brief Print distance matrix.
 *
 *  @param distance Distance matrix 
 *  @param num_city Matrix size 
 *  @return Void 
 */
void print_dist(float ***distance, size_t num_city);

/** @brief Print coordinates matrix.
 *
 *  @param coord    Coordinate matrix 
 *  @param num_city Matrix size 
 *  @return Void 
 */
void print_cord(float ***coord, size_t num_city);

/** @brief Print report.
 *
 *  @param coord    Coordinate matrix
 *  @param distance Distance matrix
 *  @param min_path Minimal path array
 *  @param num_city Matrix size
 *  @param min_len  Minimal length 
 *  @param inter    Number of simulations
 *  @param mode     Print mode
 *  @return Void 
 */
void print_repo(float **coord, float **distance, int *min_path, int num_city, float min_len, long double inter, int mode);
