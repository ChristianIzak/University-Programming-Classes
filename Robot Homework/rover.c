//
// Created by Christian Izak on 3/18/26.
//

#include "rover.h"

#include <stdio.h>
#include <stdlib.h>

void rover_status(float x, float y, double battery) {
    printf("Rover Status:\nLocation: [X=%.1f, Y=%.1f]\nBattery: %.1lf%%\n", x, y, battery);
}

void fin_rover_status(float x, float y, double battery) {
    printf("Final Rover Status:\nLocation: [X=%.1f, Y=%.1f]\nBattery: %.1lf%%\n", x, y, battery);
}

int moveType(float rover_x, float rover_y, float new_rover_x, float new_rover_y) {
    if ((new_rover_y != rover_y) && ((new_rover_x - rover_x) == 0.0)) {
        // This move type is if Y changes and X does not
        return 1;
    } else if (((new_rover_x != rover_x) && ((new_rover_y - rover_y) == 0.0))) {
        // This move type is if X changes and Y does not
        return 2;
    } else if ((new_rover_x == 0.0 && new_rover_y == 0.0)) {
        // This move type is if the robot goes back to base and shuts down
        return 3;
    } else {
        //printf("Error. Move Type 0!");
        return 0;
    }
}

void move_robot(float* rover_x, float* rover_y, float* new_rover_x, float* new_rover_y, double* battery, int moveType, int* alive) {

    switch (moveType) {
        case 1:
            // If Y position does not change but X does

            int offset1 = (int)(*new_rover_y - *rover_y);

            for (int i = 1; i <= abs(offset1); i++) {

                if (*battery >= 1.0) {
                    *battery -= 1;
                    if (offset1 < 0)
                    {
                        *rover_y -= 1;
                    }
                    else
                    {
                        *rover_y += 1;
                    }

                    printf("Rover moving...\n");

                    rover_status(*rover_x, *rover_y, *battery);
                } else {
                    printf("Out of battery! Move incomplete.\n");
                    *alive = 0;
                    break;
                }
                // if (*rover_y == *new_rover_y) { printf("Move Complete!"); break; }
            }
            break;

        case 2:
            // This move type is if Y changes and X does not

            int offset2 = (int)(*new_rover_x - *rover_x);

            for (int i = 1; i <= abs(offset2); i++) {
                if (*battery >= 1.0) {
                    *battery -= 1;
                    if (offset2 < 0)
                    {
                        *rover_x -= 1;
                    }
                    else
                    {
                        *rover_x += 1;
                    }

                    printf("Rover moving...\n");

                    rover_status(*rover_x, *rover_y, *battery);
                } else {
                    printf("Out of battery! Move incomplete.\n");
                    *alive = 0;
                    break;
                }
            }
            break;

        case 3:
            *alive = 0;
            break;

        default: break;
    }
}