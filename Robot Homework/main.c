#include <stdio.h>
#include "rover.h"

int main()
{

    // Initialize the two floats
    float rover_x, rover_y;

    // Scan the floats
    scanf("%f", &rover_x);
    scanf("%f", &rover_y);

    // Initialize the battery
    double battery;

    // Scan the battery
    scanf("%lf", &battery);

    // Print Status
    printf("Rover Status:\n");
    print_status(rover_x, rover_y, battery);

    // Initialize the loop
    while (1)
    {

        // Initialize the two new floats
        float new_rover_x, new_rover_y;

        // Scan the floats
        scanf("%f", &new_rover_x);
        scanf("%f", &new_rover_y);

        // Check if its a valid move
        int valid_move = is_move_valid(rover_x, rover_y, new_rover_x, new_rover_y);

        // Process what action to take
        switch (valid_move)
        {
        case -1:
            return 0;
        case 0:
            continue;
        default:
            move_rover(&rover_x, &rover_y, new_rover_x, new_rover_y, &battery);
            ;
        }

        printf("Final Rover Status:\n");
        print_status(rover_x, rover_y, battery);
    }

    return 0;
}