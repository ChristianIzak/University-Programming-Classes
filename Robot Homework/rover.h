//
// Created by Christian Izak on 3/18/26.
//

#ifndef ROVER_H
#define ROVER_H

void rover_status(float x, float y, double battery);
void fin_rover_status(float x, float y, double battery);
void move_robot(float* rover_x, float* rover_y, float* new_rover_x, float* new_rover_y, double* battery, int moveType, int* alive);
int moveType(float rover_x, float rover_y, float new_rover_x, float new_rover_y);

#endif //ROVER_ROVER_H