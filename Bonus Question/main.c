#include <stdio.h>
#include "scheduler.h"

int main () {
    int W = 2;
    int nodes = 3;
    int global_time = 5;

    // We represent the 2D matrix as a 1D array in contiguous memory
    int test_loads [15] = {
        5 , 2 , 8 , 4 , 1 , // Node 0
        3 , 6 , 2 , 9 , 4 , // Node 1
        7 , 3 , 9 , 6 , 2 // Node 2
    };

    // ’ test_loads’ acts as a pointer to the first element
    int best_time = find_max_lookahead_window(test_loads, W, nodes, global_time);

    printf("Optimal starting time slot : % d \n " , best_time );
}