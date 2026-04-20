/* * rover.h
* Function declarations for the Mars Rover.
*/
// Include guard (good practice, optional but recommended)
#ifndef ROVER_H
#define ROVER_H
#include "map.h"
#include "objects.h"

/**
* Prints the current status of the rover.
*/
void print_status(Rover *rover);

/**
* Checks if a move is valid and returns a status code.
*/
int scan_current_tile(Rover *rover, World *world, int new_rover_x, int new_rover_y);

/**
* Moves the rover sequentially toward a target, one unit at a time.
*/
void perform_move(Rover* rover, World* world, char* direction, int distance);
    
#endif // ROVER_H