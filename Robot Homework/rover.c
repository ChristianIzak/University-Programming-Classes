// Example inside rover.c
#include "rover.h"
#include <string.h>
#include <stdio.h> // For printf

void print_status(int rover_x, int rover_y, double battery)
{

    // Print status
    printf("Location: [X=%d, Y=%d]\n", rover_x, rover_y);
    printf("Battery: %.1lf%%\n", battery);
}

int scan_current_tile(int rover_x, int rover_y, double battery,
    char my_map[MAP_HEIGHT][MAP_WIDTH]) 
    {
    
    if (battery < 1.0) {
        printf("Out of battery!\n");
        return 500;
    } else if(rover_x < 0 || rover_x >= MAP_WIDTH || rover_y < 0 || rover_y >= MAP_HEIGHT) {
        printf("Rover is out of bounds!\n");
        return 502;
    } else if(my_map[rover_x][rover_y] == 'X') {
        printf("Obstacle detected!\n");
        return 501;
    } else {
        return 200;
    }
}

void perform_move(int *rover_x, int *rover_y, double *battery, char my_map[MAP_HEIGHT][MAP_WIDTH], char *direction, int distance) {
    int distanceLeft = distance;

    while (distanceLeft > 0) {
        if(strcmp(direction, "north") == 0) {
            switch (scan_current_tile(*rover_x, (*rover_y) - 1, *battery, my_map)) {
                case 500:
                    return;
                case 501:
                    return;
                case 502:
                    return;
                default:
                    (*rover_y)--;
                    (*battery)--;
                    if(my_map[*rover_x][*rover_y] == 'S') {
                        printf("Sample collected!\n");
                        my_map[*rover_x][*rover_y] = '.'; // Mark sample as collected
                    }
            }
        } else if(strcmp(direction, "south") == 0) {
            switch (scan_current_tile(*rover_x, (*rover_y)+1, *battery, my_map)) {
                case 500:
                    return;
                case 501:
                    return;
                case 502:
                    return;
                default:
                    (*rover_y)++;
                    (*battery)--;
                    if(my_map[*rover_x][*rover_y] == 'S') {
                        printf("Sample collected!\n");
                        my_map[*rover_x][*rover_y] = '.'; // Mark sample as collected
                    }
            }
        } else if(strcmp(direction, "east") == 0) {
            switch (scan_current_tile((*rover_x) + 1, *rover_y, *battery, my_map)) {
                case 500:
                    return;
                case 501:
                    return;
                case 502:
                    return;
                default:
                    (*rover_x)++;
                    (*battery)--;
                    if(my_map[*rover_x][*rover_y] == 'S') {
                        printf("Sample collected!\n");
                        my_map[*rover_x][*rover_y] = '.'; // Mark sample as collected
                    }
            }
        } else if(strcmp(direction, "west") == 0) {
            switch (scan_current_tile((*rover_x)-1, *rover_y, *battery, my_map)) {
                case 500:
                    return;
                case 501:
                    return;
                case 502:
                    return;
                default:
                    (*rover_x)--;
                    (*battery)--;
                    if(my_map[*rover_x][*rover_y] == 'S') {
                        printf("Sample collected!\n");
                        my_map[*rover_x][*rover_y] = '.'; // Mark sample as collected
                    }
            }
        }
        distanceLeft--;
    }
}