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
        }
    }

    int max = 0;
    int index = 0;

    for(int t = 0; t < global_time; t++) {
        int windowSum = 0;

        for (int i = 0; i < nodes; i++) {
            for (int j = 0; j < W; j++) {
                windowSum += *((loads + (i * global_time)) + (t + j));
            }
        }
        if(windowSum > max) { max = windowSum; index = t; };
    }

    return index;
}