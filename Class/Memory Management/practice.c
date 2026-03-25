#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int* arr;
    arr = calloc(4, sizeof(int));
    arr = realloc(arr, 6*sizeof(int));

    char* s = calloc(600, sizeof(char));
    char* p = malloc(600 * sizeof(char));

    // Initializes 1 pointer pointing to a block of 50. Calloc then makes 5 blocks
    int* matrix[50] = calloc(5, sizeof(*matrix)); // char matrix[5][50]

    return 0;
}