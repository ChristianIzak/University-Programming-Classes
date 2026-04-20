/* * map.h
 * Defines map constants and function prototypes for map operations.
 */
#ifndef MAP_H
#define MAP_H

#include "objects.h"

/**
 * Initializes a 2D map array in memory.
 * It first fills the map with ’.’ (open terrain).
 * Then, it places obstacles (’X’) and samples (’S’)
 * based on the coordinate arrays provided.
 *
 */
void init_map(World *world,
              int *obs_x, int *obs_y, int nObstacles,
              int *samp_x, int *samp_y, int nSamples);
/**
 * Prints the map to the console.
 * It prints the rover’s ’R’ at its current position.
 */
void print_map(World *world, Rover *rover);

#endif // MAP_H