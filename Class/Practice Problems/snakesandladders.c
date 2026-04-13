#include <stdio.h>
#include <stdlib.h>
#include "types.h"

void initializeGrid(struct Grid *b);

int main(void) {
    struct Grid board;

    scanf("%d", &board.numSnakes);
    scanf("%d", &board.numLadders);

    for(int i = 0; i< board.numSnakes; i++) {
        printf("Enter length of the snake: ");
        scanf("%d", &board.snakePositions[i].length);
        for(int j = 0; j < board.snakePositions[i].length; j++) {
            scanf("%d %d", &board.snakePositions[i].coords[j][0], &board.snakePositions[i].coords[j][1]);
        }
    }

    for(int i = 0; i< board.numLadders; i++) {
        printf("Enter length of the ladder: ");
        scanf("%d", &board.ladderPositions[i].length);
        for(int j = 0; j < board.ladderPositions[i].length; j++) {
            scanf("%d %d", &board.ladderPositions[i].coords[j][0], &board.ladderPositions[i].coords[j][1]);
        }
    }

    initializeGrid(&board);

    return 0;
}

void initializeGrid(struct Grid *b) {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            printf("* ");
        }
        printf("\n");
    }
}