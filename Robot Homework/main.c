#include <stdio.h>
#include <stdlib.h>
#include "rover.h"
#include "map.h"

int main()
{

    char my_map[MAP_HEIGHT][MAP_WIDTH];

    int nObstacles, nSamples, *obs_x, *obs_y, *samp_x, *samp_y, rover_x, rover_y;

    double battery;

    /*printf("Enter number of coordinates for obstacles: ");
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
    }*/

    nObstacles = rand() % 5;
    nSamples = rand() % 5;

    obs_x = malloc(nObstacles * sizeof(int));
    obs_y = malloc(nObstacles * sizeof(int));

    samp_x = malloc(nSamples * sizeof(int));
    samp_y = malloc(nSamples * sizeof(int));

    for (int i = 0; i < nObstacles; i++) {
        obs_x[i] = rand() % 10;
    }

    for (int i = 0; i < nObstacles; i++) {
        obs_y[i] = rand() % 10;
    }

    
    for (int i = 0; i < nSamples; i++) {
        samp_x[i] = rand() % 10;
    }

    for (int i = 0; i < nSamples; i++) {
        samp_y[i] = rand() % 10;
    }

    printf("Enter initial X: ");
    scanf("%d", &rover_x);

    printf("Enter initial Y: ");
    scanf("%d", &rover_y);

    printf("Enter initial battery: ");
    scanf("%lf", &battery);

    init_map(my_map, obs_x, obs_y, nObstacles, samp_x, samp_y, nSamples);

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
            print_status(rover_x, rover_y, battery);
        } else if(strcmp(command, "map") == 0) {
            print_map(my_map, rover_x, rover_y);
        } else if(strcmp(command, "move") == 0) {
            sscanf(line, "%*s %s %d", direction, &distance);
            perform_move(&rover_x, &rover_y, &battery, my_map, direction, distance);
        } else {
            printf("Unknown command. ");
        }
    }
    return 0;
}