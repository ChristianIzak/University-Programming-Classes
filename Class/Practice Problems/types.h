// In types.h
#ifndef TYPES_H
#define TYPES_H

// Struct to hold coordinates of something
struct Point {
    int x;
    int y;
};

// Snakes have some length, and the points where
// they are placed
struct Snake {
    struct Point coords[10];
    int length;
};

// Same as snake
struct Ladder {
    struct Point coords[10];
    int length;
};

// The grid contains some snakes and some ladders!
struct Grid {
    char grid[10][10];
    int numSnakes;
    int numLadders;
    struct Snake snakePositions[10];
    struct Ladder ladderPositions[10];
};

#endif