#include <stdio.h>

int main(void) {
    int array[17] = {10, 0, 0, 20, 0, 0, 30, 0, 0, 40, 0, 50, 123, 4, 0, 0, 910};
    int* pointer = array;

    for(int i = 0; i < 17; i++) {
        int* lpoint = pointer+i;
        if(*lpoint != 0) {
            printf("%d\n", array[i]);
        }
    }

    return 0;
}