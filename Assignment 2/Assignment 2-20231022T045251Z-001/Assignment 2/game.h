#ifndef GAME_H
#define GAME_H

struct Map; /* Forward declaration */

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
int clearGame();
int printGame(Map* map, GameState* gameState);

#endif
