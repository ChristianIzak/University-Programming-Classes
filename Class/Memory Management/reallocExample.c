#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *arr = calloc(3, sizeof(int));
    arr[0] = 1; arr[1] = 2; arr[2] = 3;

    // Grow to 6 elements
    arr = realloc(arr, 6 * sizeof(int));
    arr[3] = 4; arr[4] = 5; arr[5] = 6;

    for(int i = 0; i < 6; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    arr = NULL;
}