#include <stdio.h>
#include "map.h"

void init_map(char my_map[MAP_HEIGHT][MAP_WIDTH],
              int *obs_x, int *obs_y, int nObstacles,
              int *samp_x, int *samp_y, int nSamples) 
    {

    // Fill the map with '.' (open terrain)
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            my_map[i][j] = '.';
        }
    }

    for (int i = 0; i < nObstacles; i++) {
        int x = obs_x[i];
        int y = obs_y[i];
        if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT) {
            my_map[y][x] = 'X'; // Place obstacle
        }
    }

    for (int i = 0; i < nSamples; i++) {
        int x = samp_x[i];
        int y = samp_y[i];
        if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT) {
            my_map[y][x] = 'S'; // Place sample
        }
    }
}


void print_map(char my_map[MAP_HEIGHT][MAP_WIDTH],
               int rover_x, int rover_y) 
    {

    for(int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            if (i == rover_y && j == rover_x) {
                printf("R "); // Print rover at its current position
            } else {
                printf("%c ", my_map[i][j]); // Print the map cell
            }
        }
        printf("\n");
    }
}