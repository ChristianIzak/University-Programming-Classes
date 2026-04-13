// In utils.c
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

/**
 * @brief Initializes the game board by setting up the empty grid, snakes, and ladders.
 * * 1. Fills the entire 10x10 grid with '.' to represent empty spaces.
 * 2. Iterates through all snakes and marks their specific coordinates with 'S'.
 * 3. Iterates through all ladders and marks their coordinates. If a ladder 
 * happens to overlap with a previously placed snake ('S'), that tile is 
 * marked with 'X' to indicate a collision. Otherwise, it is marked with 'L'.
 *
 * @param grid Pointer to the Grid structure.
 */
void initializeGrid(struct Grid* grid)
{
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            grid->grid[i][j] = '.';
        }
    }

    for(int i = 0; i < grid->numSnakes; i++)
    {
        for(int j = 0; j < grid->snakePositions[i].length; j++)
        {
            grid->grid[grid->snakePositions[i].coords[j].x][grid->snakePositions[i].coords[j].y] = 'S';
        }
    }

    for(int i = 0; i < grid->numLadders; i++) {
        for(int j = 0; j < grid->ladderPositions[i].length; j++) {
            if(grid->grid[grid->ladderPositions[i].coords[j].x][grid->ladderPositions[i].coords[j].y] == 'S') {
                grid->grid[grid->ladderPositions[i].coords[j].x][grid->ladderPositions[i].coords[j].y] = 'X';
            }
            else {
                grid->grid[grid->ladderPositions[i].coords[j].x][grid->ladderPositions[i].coords[j].y] = 'L';
            }
            
        }
    }
}

/**
 * @brief Prints the current state of the 10x10 grid to the console.
 *
 * Iterates through every cell in the grid and checks if either 
 * player is on the current cell instead of the board tile:
 * - Prints "B " if both players occupy the same tile.
 * - Prints "1 " if only Player 1 is on the tile.
 * - Prints "2 " if only Player 2 is on the tile.
 * - Prints the grid character ('.', 'S', 'L', or 'X') if no players are present.
 *
 * @param grid Pointer to the Grid structure containing the board data.
 * @param player1 Pointer to Player 1's current coordinate point.
 * @param player2 Pointer to Player 2's current coordinate point.
 */
void printGrid(struct Grid* grid, struct Point* player1, struct Point* player2)
{
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {

            if((player1->x == i && player1->y == j) && (player2->x == i && player2->y == j)) {
                printf("B ");
            }
            else if(player1->x == i && player1->y == j) {
                printf("1 ");
            }
            else if(player2->x == i && player2->y == j) {
                printf("2 ");
            }
            else {
                printf("%c ", grid->grid[i][j]);
            }
        }
        printf("\n");
    }
}

/**
 * @brief Executes a single turn for a player, including dice roll and movement.
 *
 * Prompts the user to roll a die, calculates the player's current 1D position 
 * based on a zig-zag board layout, adds the dice roll, and computes the new 
 * 2D coordinates. If the new position exceeds the final tile (99), the move 
 * is ignored and the function returns early. Otherwise, it updates the player's 
 * coordinates and checks for snake or ladder interactions.
 *
 * @param player Pointer to the Point structure representing the player's current position.
 * @param grid Pointer to the Grid structure containing the board data.
 */
void playMove(struct Point* player, struct Grid* grid)
{
    // Roll the dice (1 to 6)
    char ch;
    printf("Press enter to roll dice!");
    scanf("%c", &ch);
    int diceRoll = rand() % 6 + 1;
    printf("Player rolled a %d!\n", diceRoll);

    // Convert current 2D coordinates to a 1D position 
    int currentPos;
    if (player->x % 2 == 0) {
        // Even rows (0, 2, 4...) run left-to-right normally
        currentPos = (player->x * 10) + player->y;
    } else {
        // Odd rows (1, 3, 5...) run right-to-left
        currentPos = (player->x * 10) + (9 - player->y);
    }
    
    // Add the dice roll to get the new position
    int newPos = currentPos + diceRoll;

    if (newPos > 99) {
        player->x = 9;
        player->y = 0;
        return;
    }

    // Convert the 1D position back to 2D zig-zag coordinates
    int newX = newPos / 10;
    int newY;
    
    if (newX % 2 == 0) {
        // Even rows run left-to-right
        newY = newPos % 10;
    } else {
        // Odd rows run right-to-left
        newY = 9 - (newPos % 10); 
    }

    // Update the player's position
    player->x = newX;
    player->y = newY;

    // TODO: This is homework

    // // Check if a snake head is at newX and newY
    // for() {
    //     if() {

    //     }
    // }
    // // Check if a ladder head is at newX and newY
    // for() {
    //     if() {
            
    //     }
    // }
}

/**
 * @brief Checks if a player has reached the final winning tile.
 *
 * Determines if the player's current coordinates match the end of the board 
 * (specifically x = 9 and y = 9).
 *
 * @param player Pointer to the Point structure representing the player's current position.
 * @param grid Pointer to the Grid structure containing the board data.
 * @return int Returns 1 if the player is on the winning tile, 0 otherwise.
 */
int isWinner(struct Point* player, struct Grid* grid)
{
    if(player->x == 9 && player->y == 0) {
        return 1;
    }
    return 0;
}
