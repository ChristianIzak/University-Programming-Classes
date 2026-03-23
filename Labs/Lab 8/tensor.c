#include <stdio.h>

int main(void) {

    int array[2][3][4];
    printf("\n");

    int count = 0;

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 4; k++) {
                count++;
                array[i][k][j] = count;
                printf("\t%d", array[i][k][j]);
            }
            printf("\n\n");
        }
        printf("\n");
    }

    /*
    
    {
        x, x, x, x 
        x, x, x, x
        x, x, x, x
    },
    {
        x, x, x, x 
        x, x, x, x
        x, x, x, x
    }
    
    */

    return 0;
}