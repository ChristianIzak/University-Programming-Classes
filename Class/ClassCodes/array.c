#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main (void) {
    int start;
    int step;
    int count;

    int* aP = malloc(count * sizeof(int));
    int* gP = malloc(count * sizeof(int));

    printf("Enter Start, Step, Count: ");
    scanf("%d %d %d", &start, &step, &count);

    createArathmaticProgression(start, step, count, aP);

    printSequence(aP, count);

    createGeometricProgression(start, step, count, gP);

    printSequence(gP, count);

    free(aP);
    free(gP);
    aP = NULL;
    gP = NULL;

    return 0;
}