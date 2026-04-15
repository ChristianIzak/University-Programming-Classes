#include <stdio.h>
#include "scheduler.h"

// TODO : Implement your function here without using []!
int find_max_lookahead_window (int* loads, int W, int nodes, int global_time) {
    // Your highly optimized, pointer-arithmetic code goes here.

    for(int i = 0; i < nodes; i++) {
        for(int j = 0; j < global_time; j++) {
            if((*((loads + (global_time*i)) + j) % (i+1)) != 0) {
                *((loads + (global_time*i)) + j) = 0;
            }

            printf("%d ", *((loads + (global_time*i)) + j));
        }  
        printf("\n");
    }

    int max = 0;
    int index = 0;

    for(int i = 0; i < nodes; i++) {
        int nodeMax = 0;
        for(int j = 0; j < W; j++) {
            nodeMax += *((loads + (i*global_time)) + j);
        }

        printf("Node Max: %d\nMax: %d\n", nodeMax, max);

        if(nodeMax > max) { max = nodeMax; index = i; };
    }

    return index;
}