#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "utils.h"

// [1, 3, 5, 7, 9, ...]
// Start = 1, Step = 2, Count = 5
void createArathmaticProgression(int start, int step, int count, int* sum) {
    sum[0] = start;

    for(int i = 1; i < count; i++) {
        sum[i] += start + (step*i);
    }
}

void createGeometricProgression(int start, int step, int count, int* sum) {
    for(int i = 0; i < count; i++) {
        sum[i] = start*(pow(step, i));
    }
}

void printSequence (int* array, int count) {
    for(int i = 0; i < count; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}