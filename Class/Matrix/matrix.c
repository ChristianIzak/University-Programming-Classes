#include "matrix.h"

void transpose(int array[100][100], int* N, int* M) {
    for(int i = 0; i < *M; i++) {
        for (int j = i + 1; j < *N; j++) {

            int temp = array[i][j];
            
            array[i][j] = array[j][i];
            array[j][i] = temp;
        }
    }

    int temp = *M;
    *M = *N;
    *N = M;
}

void add(int result[100][100], int m1[100][100], int m2[100][100], int N, int M) {

}