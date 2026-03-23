#include <stdio.h>

int main(void) {
    int matrixA[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int matrixB[3][2] = {{7, 8}, {9, 1}, {2, 3}};
    int matrixC[2][2] = {{0, 0}, {0, 0}};

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++) {
                matrixC[i][j] += (matrixA[i][k] * matrixB[k][j]);
            }
            printf("%d ", matrixC[i][j]);
        }
        printf("\n");
    }

    return 0;
}