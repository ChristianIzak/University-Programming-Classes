#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *ptr = calloc(4, sizeof(int));

    ptr[0] = 10;
    ptr[1] = 20;
    ptr[2] = 30;
    ptr[3] = 40;

    for(int i = 0; i < 4; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    free(ptr);
    ptr = NULL;

    return 0;
}