#include <stdio.h>
#include <math.h>
#include "rover.h"

//battery = battery - sqrt(pow((new_rover_x - rover_x), 2) + pow((new_rover_y - rover_y), 2));

int main(void) {
    float rover_x, rover_y;
    float new_rover_x, new_rover_y;
    double battery;
    int alive = 1;

    // Initialization settings

    scanf("%f", &rover_x);
    scanf("%f", &rover_y);
    scanf("%lf", &battery);

    //rover_status(rover_x, rover_y, battery);

    printf("Rover Status:\nLocation: [X=%.1f, Y=%.1f]\nBattery: %.1lf%%\n", rover_x, rover_y, battery);

    // Start the loop to move robot and check if valid

    while (alive) {
        scanf("%f", &new_rover_x);
        scanf("%f", &new_rover_y);

        //printf("\nMove Type: %d\n\n", moveType(rover_x, rover_y, new_rover_x, new_rover_y));

        switch (moveType(rover_x, rover_y, new_rover_x, new_rover_y)) {
            case 1:
                // In this case, the robot will move in the Y direction (Move type 1)
                move_robot(&rover_x, &rover_y, &new_rover_x, &new_rover_y, &battery, 1, &alive);
                fin_rover_status(rover_x, rover_y, battery);
                continue;
            case 2:
                // In this case, the robot will move in the X direction (Move type 2)
                move_robot(&rover_x, &rover_y, &new_rover_x, &new_rover_y, &battery, 2, &alive);
                fin_rover_status(rover_x, rover_y, battery);
                continue;
            case 3:
                // In this case, the robot will shut down because the user inputted the coordinates (0,0)
                move_robot(&rover_x, &rover_y, &new_rover_x, &new_rover_y, &battery, 3, &alive);
                //fin_rover_status(rover_x, rover_y, battery);
                break;
            default:
                printf("Cannot move diagonally!\n");
        }
    }

    printf("Shutting down.");

    return 0;
}