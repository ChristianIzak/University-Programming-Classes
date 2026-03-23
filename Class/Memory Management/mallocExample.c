#include <stdio.h>

int main(void) {

    int *p = malloc(10 * sizeof(int));

    int *q = calloc(10, sizeof(int));

    return 0;
}