// In main.c/snakesandladders.c
#include <stdio.h>
#include <stdlib.h>

// These files have our functions and struct definitions
#include "types.h"
#include "utils.h"

int main() {

    // Initialize a new game
    struct Grid board;

    scanf("%d", &board.numSnakes);  // Input the number of snakes (has to be lower than 10)
    scanf("%d", &board.numLadders); // Input the number of ladders (has to be lower than 10)

    for(int i = 0; i < board.numSnakes; i++) {
        printf("Enter length of the snake: ");
        scanf("%d", &board.snakePositions[i].length);   // Scan the length of the current snake i
        for(int j = 0; j < board.snakePositions[i].length; j++) {
            // This just takes the x coordinates and y coordinates point by point for the current snake i
            scanf("%d %d", &board.snakePositions[i].coords[j].x, &board.snakePositions[i].coords[j].y);
        }
    }

    // We do the same exact thing for the ladders
    for(int i = 0; i < board.numLadders; i++) {
        printf("Enter length of the ladder: ");
        scanf("%d", &board.ladderPositions[i].length);
        for(int j = 0; j < board.ladderPositions[i].length; j++) {
            scanf("%d %d", &board.ladderPositions[i].coords[j].x, &board.ladderPositions[i].coords[j].y);
        }
    }
    
    // Put '.' where there is no snake or ladder
    // Put 'L' where there is a ladder
    // Put 'S' where there is a snake
    // Put 'X' where S and L intersect
    initializeGrid(&board);

    // Players are just points on the board!
    struct Point player1, player2;
    player1.x = 0;
    player1.y = 0;
    player2.x = 0;
    player2.y = 0;

    // Start the game!
    while(1) {

        // First we print the grid after each move
        printGrid(&board, &player1, &player2);

        // Player 1 goes first
        playMove(&player1, &board);
        if(isWinner(&player1, &board)) {
            // Player 1 has won!
            printf("\nPlayer 1 is the winner!");
            break;
        }
        // Player 2 goes next!
        playMove(&player2, &board);
        if(isWinner(&player2, &board)) {
            // Player 2 wins!
            printf("\nPlayer 2 is the winner!");
            break;
        }
    }

    printGrid(&board, &player1, &player2);

    return 0;
}