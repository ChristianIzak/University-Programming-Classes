// Example inside rover.c
#include "rover.h"
#include <string.h>
#include <stdio.h> // For printf
#include "objects.h"

void print_status(Rover* rover)
{

    // Print status
    printf("Location: [X=%d, Y=%d]\n", rover->x, rover->y);
    printf("Battery: %.1lf%%\n", rover->battery);
    printf("Samples: %d\n", rover->samples_collected);
}

int scan_current_tile(Rover* rover, World* world, int new_rover_x, int new_rover_y)
{
    if (rover->battery < 1.0) {
        printf("Out of battery!\n");
        return 500;
    }
    else if (new_rover_x < 0 || new_rover_x >= MAP_HEIGHT ||
        new_rover_y < 0 || new_rover_y >= MAP_WIDTH) {
        printf("Hit map boundary!\n");
        return 502;
    }
    else if (world->map[new_rover_x][new_rover_y] == 'X') {
        printf("Obstacle detected!\n");
        return 501;
    }
    else {
        return 200;
    }
}

void perform_move(Rover* rover, World* world, char* direction, int distance) {
    int distanceLeft = distance;

    while (distanceLeft > 0) {
        if(strcmp(direction, "east") == 0) {
            switch (scan_current_tile(rover, world->map, rover->x, (rover->y) + 1)) {
                case 500:
                    return;
                case 501:
                    return;
                case 502:
                    return;
                default:
                    rover->y++;
                    rover->battery--;
                    if(world->map[rover->x][rover->y] == 'S') {
                        printf("Sample collected!\n");
                        rover->samples_collected++;
                        world->map[rover->x][rover->y] = '.'; // Mark sample as collected
                    }
            }
        } else if(strcmp(direction, "west") == 0) {
            switch (scan_current_tile(rover, world->map, rover->x, (rover->y) - 1)) {
                case 500:
                    return;
                case 501:
                    return;
                case 502:
                    return;
                default:
                    (rover->y)--;
                    (rover->battery)--;
                    if(world->map[rover->x][rover->y] == 'S') {
                        printf("Sample collected!\n");
                        rover->samples_collected++;
                        world->map[rover->x][rover->y] = '.'; // Mark sample as collected
                    }
            }
        } else if(strcmp(direction, "south") == 0) {
            switch (scan_current_tile(rover, world->map, (rover->x) + 1, rover->y)) {
                case 500:
                    return;
                case 501:
                    return;
                case 502:
                    return;
                default:
                    (rover->x)++;
                    (rover->battery)--;
                    if(world->map[rover->x][rover->y] == 'S') {
                        printf("Sample collected!\n");
                        rover->samples_collected++;
                        world->map[rover->x][rover->y] = '.'; // Mark sample as collected
                    }
            }
        } else if(strcmp(direction, "north") == 0) {
            switch (scan_current_tile(rover, world->map, (rover->x)-1, rover->y)) {
                case 500:
                    return;
                case 501:
                    return;
                case 502:
                    return;
                default:
                    (rover->x)--;
                    (rover->battery)--;
                    if(world->map[rover->x][rover->y] == 'S') {
                        printf("Sample collected!\n");
                        rover->samples_collected++;
                        world->map[rover->x][rover->y] = '.'; // Mark sample as collected
                    }
            }
        }
        distanceLeft--;
    }
}