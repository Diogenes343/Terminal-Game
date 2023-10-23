#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "fileReader.h"
#include "carMovement.h"

#define MAP_BORDER '*'
#define ROAD '.'
#define PLAYER 'P'
#define CAR_LEFT '<'
#define CAR_RIGHT '>'
#define CAR_UP '^'
#define CAR_DOWN 'v'
#define CAR_CRASH 'X'
#define GOAL 'G'


void intialiseGame(Map *map, GameState *gameState, Car *car) {

    int i;
    int j;
    int carIndex;


    gameState->gameMap = (char **)malloc(map->row * sizeof(char *));
    for (i = 0; i < map->row; i++) {
        gameState->gameMap[i] = (char *)malloc(map->col * sizeof(char));
    }

    /* Car code*/

    for(i = 0; i < map->row; i++){
        for(j = 0; j < map->col; j++){
            if(i > 0 || i == map->row - 1 || j > 0 || j == map->col- 1){
                gameState->gameMap[i][j] = '*';    /* create map border*/
            }else if( gameState->gameMap[i][j] == 0){
                gameState->gameMap[i][j] = ' ';    /* empty space */
            }else if( gameState->gameMap[i][j] == 1){
                gameState->gameMap[i][j] = '.';    /* road */
            }else if ( gameState->gameMap[i][j] == 2){
                gameState->gameMap[i][j] = '>';    /* car facing right */
                car->carRow = i;
                car->carCol = j;
            }else if ( gameState->gameMap[i][j] == 3){
                gameState->gameMap[i][j] = 'P';
                gameState->playerRow = i;
                gameState->playerCol = j;    /* player */
            }else if ( gameState->gameMap[i][j] == 4){
                gameState->gameMap[i][j] = 'G';
                gameState->goalRow = i;
                gameState->goalCol = j;    /* goal */
            }
        }
    }



}

int updateGame(char move, Map *map, GameState *gameState, Car *car) {


    int newPlayerRow, newPlayerCol;
    newPlayerRow = gameState->playerRow;
    newPlayerCol = gameState->playerCol;
    /*moveCar(int* carRow, int* carCol, int* direction, char** gameMap, int mapRow, int mapCol)*/

    switch(move) {
        case 'w':
            newPlayerRow --;
            break;
        case 'a':
            newPlayerCol --;
            break;
        case 's':
            newPlayerRow --;
            break;
        case 'd':
            newPlayerCol --;
            break;
        /*case 'u':
            undo feature
            undoGameState(map);
            break;*/
    }

    if (newPlayerRow > 0 && newPlayerRow < map->row - 1 && newPlayerCol > 0 && newPlayerCol < map->col -1){
        gameState->playerRow = newPlayerRow;
        gameState->playerCol = newPlayerCol;

        gameState->gameMap[newPlayerRow][newPlayerCol] = 'P';

        if(gameState->gameMap[newPlayerRow][newPlayerCol] == gameState->gameMap[car->carRow][car->carCol]){
            gameState->gameMap[newPlayerRow][newPlayerCol] = 'X';
            printf("you lose!");
            endGame();
        }

        if (gameState->gameMap[newPlayerRow][newPlayerCol] == 'G'){
            printf("you win!");
            endGame();
        }
    }
}

int endGame() {
    int gameOverflag = 1;
    return gameOverflag;
}

int clearGame() {

}

int printGame(Map* map, GameState* GameState) {
    int i, j;
    for(i = 0; i < map->row; i++){
        for(j = 0; j < map->col; j++){
            printf("%c", GameState->gameMap[i][j]);
        }
        printf("\n");
    }
}