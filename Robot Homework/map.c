#include <stdio.h>
#include "map.h"

void init_map(World* world,
    int* obs_x, int* obs_y, int nObstacles,
    int* samp_x, int* samp_y, int nSamples)
    {

    // Fill the map with '.' (open terrain)
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            world->map[i][j] = '.';
        }
    }

    for (int i = 0; i < nObstacles; i++) {
        int x = obs_x[i];
        int y = obs_y[i];
        if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT) {
            world->map[x][y] = 'X'; // Place obstacle
        }
    }

    for (int i = 0; i < nSamples; i++) {
        int x = samp_x[i];
        int y = samp_y[i];
        if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT) {
            world->map[x][y] = 'S'; // Place sample
        }
    }
}


void print_map(World* world, Rover* rover)
    {

    for(int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            if (i == rover->x && j == rover->y) {
                printf("R"); // Print rover at its current position
            } else {
                printf("%c", world->map[i][j]); // Print the map cell
            }
        }
        printf("\n");
    }
}