#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rover.h"
#include "map.h"
#include "objects.h"

int main()
{

    World world;
    Rover rover = {0, 0, 0};

    int nObstacles, nSamples, *obs_x, *obs_y, *samp_x, *samp_y;

    printf("Enter number of coordinates for obstacles: ");
    scanf("%d", &nObstacles);

    printf("Enter number of coordinates for samples: ");
    scanf("%d", &nSamples);

    obs_x = malloc(nObstacles * sizeof(int));
    obs_y = malloc(nObstacles * sizeof(int));

    samp_x = malloc(nSamples * sizeof(int));
    samp_y = malloc(nSamples * sizeof(int));

    printf("Enter X coordinates of obstacles: ");
    for (int i = 0; i < nObstacles; i++) {
        scanf("%d", &obs_x[i]);
    }

    printf("Enter Y coordinates of obstacles: ");
    for (int i = 0; i < nObstacles; i++) {
        scanf("%d", &obs_y[i]);
    }

    printf("Enter X coordinates of samples: ");
    for (int i = 0; i < nSamples; i++) {
        scanf("%d", &samp_x[i]);
    }

    printf("Enter Y coordinates of samples: ");
    for (int i = 0; i < nSamples; i++) {
        scanf("%d", &samp_y[i]);
    }

    printf("Enter initial X: ");
    scanf("%d", &rover.x);

    printf("Enter initial Y: ");
    scanf("%d", &rover.y);

    printf("Enter initial battery: ");
    scanf("%lf", &rover.battery);

    init_map(&world, obs_x, obs_y, nObstacles, samp_x, samp_y, nSamples);

    // Clear the input buffer before switching to fgets
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }

    // Initialize the loop
    while (1)
    {

        printf("> ");

        char line[100];
        char command[100];
        char direction[100];
        int distance;

        fgets(line, sizeof(line), stdin);

        sscanf(line, "%s", command);

        if(strcmp(command, "quit") == 0) {
            break;
        } else if(strcmp(command, "status") == 0) {
            print_status(&rover);
        } else if(strcmp(command, "map") == 0) {
            print_map(&world, &rover);
        } else if(strcmp(command, "move") == 0) {
            sscanf(line, "%*s %s %d", direction, &distance);
            perform_move(&rover, &world, direction, distance);
        } else {
            printf("Unknown command. ");
        }
    }
    return 0;
}