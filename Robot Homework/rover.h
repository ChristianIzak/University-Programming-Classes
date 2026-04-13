/* * rover.h
* Function declarations for the Mars Rover.
*/
// Include guard (good practice, optional but recommended)
#ifndef ROVER_H
#define ROVER_H
#include "map.h"

/**
* Prints the current status of the rover.
*/
void print_status(int rover_x, int rover_y, double battery);

/**
* Checks if a move is valid and returns a status code.
*/
int scan_current_tile(int rover_x, int rover_y, double battery,
    char my_map[MAP_HEIGHT][MAP_WIDTH]);

/**
* Moves the rover sequentially toward a target, one unit at a time.
*/
void perform_move(int *rover_x, int *rover_y, double *battery,
    char my_map[MAP_HEIGHT][MAP_WIDTH], char *direction, int distance);
    
#endif // ROVER_H