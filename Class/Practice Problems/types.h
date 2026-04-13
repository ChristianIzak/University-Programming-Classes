#ifndef TYPES_H
#define TYPES_H

struct Snake {
    int coords[10][2];
    int length;
};

struct Ladder {
    int coords[10][2];
    int length;
};

struct Grid {
    int grid[10][10];
    int numSnakes;
    int numLadders;
    struct Snake snakePositions[10];
    struct Ladder ladderPositions[10];
};

struct Player {
    int x;
    int y;
};

#endif