/** @file     graphviz.h
 *  @brief    Header for graphviz's dot format output.
 *  @author   Brian K. (AlpacaRotorvator@users.noreply.github.com)
 *  @date     10/18/2017
 */

#ifndef GRAPHVIZ_H
#define GRAPHVIZ_H

/** @brief Output in dot format to minpath.dot.
 *
 *  @param[in] c  Coordinate matrix 
 *  @param[in] m  Minimal path array 
 *  @param[in] n  Number of cities
 *  @return void 
 */
void gen_graphviz (float ** c, int * m, int n);
#endif
