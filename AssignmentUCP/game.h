#ifndef GAME_H
#define GAME_H

#include "fileReader.h"


/* Forward declaration */

typedef struct GameState {
    char** gameMap;
    int playerRow;
    int playerCol;
    int goalRow;
    int goalCol;
} GameState;

typedef struct Car{
    int carRow;
    int carCol;
    int carDirection;
    char carCharacter;
} Car;

void intialiseGame(Map* map, GameState* gameState, Car* car);
int updateGame(char move, Map* map, GameState* gameState, Car* car);
int endGame();
void clearGame(Map* map, GameState *gameState, Car *car);
int printGame(Map* map, GameState* gameState);

#endif
