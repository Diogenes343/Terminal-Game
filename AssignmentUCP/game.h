#ifndef GAME_H
#define GAME_H

#include "fileReader.h"
#include "undoFunc.h"

/* Forward declaration */
Stack stack;

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
} Car;



void intialiseGame(Map* map, GameState* gameState, Car* car, int blank_bool);
int updateGame(char move, Map* map, GameState* blankState, GameState* gameState, Car* car, Stack* stack, int directions[4][2], char carChar);
int endGame();
void clearGame(Map* map, GameState* gameState, GameState* blankState, Car *car);
int printGame(Map* map, GameState* gameState);

#endif
