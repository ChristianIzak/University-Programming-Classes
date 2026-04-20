// Include guard (good practice, optional but recommended)
#ifndef OBJECTS_H
#define OBJECTS_H

// Define the map dimensions
#define MAP_HEIGHT 10
#define MAP_WIDTH 10

typedef struct
{
	int x;
	int y;
	double battery;
	int samples_collected;
} Rover;

typedef struct
{
	char map[MAP_HEIGHT][MAP_WIDTH];
} World;

#endif