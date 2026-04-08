// Example inside rover.c
#include "rover.h"
#include <stdio.h> // For printf

void print_status(float rover_x, float rover_y, double battery)
{

    // Print status
    printf("Location: [X=%.1f, Y=%.1f]\n", rover_x, rover_y);
    printf("Battery: %.1lf%%\n", battery);
}

int is_move_valid(float rover_x, float rover_y, float new_rover_x, float new_rover_y)
{

    if (new_rover_x == 0.0 && new_rover_y == 0.0)
    {

        // -1 for shutdown
        printf("Shutting down.");
        return -1;
    }
    else if (new_rover_x != rover_x && new_rover_y != rover_y)
    {

        // 0 for not movable
        printf("Cannot move diagonally!\n");
        return 0;
    }
    return 1;
}

void move_rover(float *rover_x, float *rover_y, float new_rover_x, float new_rover_y, double *battery)
{

    while (*rover_x != new_rover_x || *rover_y != new_rover_y)
    {

        if (*battery < 1.0)
        {
            printf("Out of battery! Move incomplete.\n");
            return;
        }

        printf("Rover moving...\n");

        *battery -= 1;

        if (*rover_x < new_rover_x)
        {
            *rover_x += 1;
        }
        else if (*rover_x > new_rover_x)
        {
            *rover_x -= 1;
        }
        else if (*rover_y < new_rover_y)
        {
            *rover_y += 1;
        }
        else if (*rover_y > new_rover_y)
        {
            *rover_y -= 1;
        }

        printf("Rover Status:\n");
        print_status(*rover_x, *rover_y, *battery);
    }
}