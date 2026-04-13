// In utils.h
#ifndef UTILS_H
#define UTILS_H

#include "types.h"

/**
 * Snakes and Ladders!
 * 1. Make a grid with the use of rand() for snakes and ladders!
 * 2. Roll a dice with rand()
 * 3. Move your pawn by that many spots on the grid
 * 4. Have a friend play with you!
 * 5. See who wins!
 * 
 * Sample Grid:
 * 
 * .    .   S   .   .   .   .   .   .   . 
 * .    .   .   S   .   .   .   S   .   .
 * .    .   S   .   .   .   S   .   .   .
 * .    .   .   S   .   S   .   .   .   .
 * .    .   .   S   .   L   .   .   .   .
 * .    .   .   S   2   .   L   .   .   .                                 
 * .    1   .   S   .   .   .   L   .   .
 * 
 */

void initializeGrid(struct Grid* grid);

// Just print the grid like we have above
void printGrid(struct Grid* grid, struct Point* player1, struct Point* player2);

// int diceRoll = (rand() % 6) + 1;
// Each player executes a dice roll and decides where to move on the grid
void playMove(struct Point* player, struct Grid* grid);

// If the player reaches the end, return 1, else 0
int isWinner(struct Point* player, struct Grid* grid);

#endif
