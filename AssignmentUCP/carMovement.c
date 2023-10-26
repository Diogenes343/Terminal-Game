#include <stdio.h>
#include <stdlib.h>
#include "carMovement.h"
#include "fileReader.h"
#include "game.h"

void moveCar(Car* car, Map* map, GameState* gameState, int directions[4][2], char carChar) {
    int i;
    int newCarRow, newCarCol;
    int validMove;
    char dir_letters[4] = {'r','d','l','u'};
    validMove = 0;
    car->carDirection = 0;

    


    for (i = 0; i < 4; i++) {
        int newDirection = (car->carDirection + i) % 4; /* Rotate direction to the next one (0 to 3). */

        if (newDirection == (car->carDirection + 2) % 4) {
            continue;
        }
        printf("the direction index is %d\n", newDirection);
        printf("We are looking %c", dir_letters[newDirection]);
        printf(" of the car.\n");
        
        newCarRow = car->carRow + directions[newDirection][0];
        newCarCol = car->carCol + directions[newDirection][1];

        printf("The row is %d", newCarRow);
        printf(", and the column is %d\n", newCarCol);

        printf("Here is the value at that position: %c\n", gameState->gameMap[newCarRow][newCarCol]);

        if (newCarRow >= 0 && newCarRow < map->row && newCarCol >= 0 && newCarCol < map->col) {
            if (gameState->gameMap[newCarRow][newCarCol] == '.') {
                validMove++;
                gameState->gameMap[car->carRow][car->carCol] = '.'; /* Mark the current position as empty. */
                printf("the direction index is %d\n", newDirection);
                printf("number of valid moves %d", validMove);
                /* Determine the new character based on direction. */
                switch (newDirection) {
                    case 0: carChar = '>'; break; /* Right */
                    case 1: carChar = 'v'; break; /* Down */
                    case 2: carChar = '<'; break; /* Left */
                    case 3: carChar = '^'; break; /* Up */
                    default: carChar = '>'; /* Default to right */
                };

                gameState->gameMap[newCarRow][newCarCol] = carChar; /* Place the car at the new position. */
                car->carRow = newCarRow;
                car->carCol = newCarCol;
                car->carDirection = newDirection; /* Update the car's direction. */
                return; /* Exit the function after a successful move. */
            }
        }
    }
    
    if (validMove > 1) {
        gameState->gameMap[car->carRow][car->carCol] = '.'; /* Mark the current position as empty. */
        printf("this occurs");
        newCarRow = car->carRow + directions[car->carDirection][0];
        newCarCol = car->carCol + directions[car->carDirection][1];

        gameState->gameMap[newCarRow][newCarCol] = car->carDirection; /* Place the car at the new position. */
        car->carRow = newCarRow;
        car->carCol = newCarCol;
        return; /* Exit the function after a successful move. */
    }

    if (validMove == 0) {
        printf("No valid move found.\n");
        printf("Invalid map\n");
        return;
    }
    printf("No valid move found.\n");
}
/*
int main() {
    int mapRow = 7;
    int mapCol = 7;
    char** gameMap = malloc(mapRow * sizeof(char*));

    for (int i = 0; i < mapRow; i++) {
        gameMap[i] = malloc(mapCol * sizeof(char));
        for (int j = 0; j < mapCol; j++) {
            gameMap[i][j] = '0';
        }
    }

    char mapData[7][7] = {
        {'0', '0', '0', '0', '0', '0', '0'},
        {'0', '.', '.', '.', '0', '0', '0'},
        {'0', '.', '0', '.', '0', '0', '0'},
        {'0', '.', '.', '.', '.', '.', '0'},
        {'0', '0', '0', '.', '0', '.', '0'},
        {'0', '0', '0', '.', '.', '.', '0'},
        {'0', '0', '0', '0', '0', '0', '0'}
    };

    for (int i = 0; i < mapRow; i++) {
        for (int j = 0; j < mapCol; j++) {
            gameMap[i][j] = mapData[i][j];
        }
    }

    Car car;
    car.carRow = 3;
    car.carCol = 3;
    car.carDirection = 0; // 0 represents right

    gameMap[car.carRow][car.carCol] = 'v'; // Initialize the car at (1, 3) with the 'right' direction

    // Call moveCar function to move the car
    moveCar(&car, gameMap, mapRow, mapCol);

    // Print the updated map
    for (int i = 0; i < mapRow; i++) {
        for (int j = 0; j < mapCol; j++) {
            printf("%c ", gameMap[i][j]);
        }
        printf("\n");
    }

    // Clean up memory
    for (int i = 0; i < mapRow; i++) {
        free(gameMap[i]);
    }
}
   
*/