#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "fileReader.h"
#include "carMovement.h"
#include "undoFunc.h"

#define MAP_BORDER '*'
#define ROAD '.'
#define PLAYER 'P'
#define CAR_LEFT '<'
#define CAR_RIGHT '>'
#define CAR_UP '^'
#define CAR_DOWN 'v'
#define CAR_CRASH 'X'
#define GOAL 'G'


void intialiseGame(Map *map, GameState *gameState, Car *car, int blank_bool) {

    int i;
    int j;


    gameState->gameMap = (char **)malloc(map->row * sizeof(char *));
    for (i = 0; i < map->row; i++) {
        gameState->gameMap[i] = (char *)malloc(map->col * sizeof(char));
    }

    /* Car code*/

    for(i = 0; i < map->row; i++){
        for(j = 0; j < map->col; j++){
            if(i == 0 || i == map->row - 1 || j == 0 || j == map->col- 1){
                gameState->gameMap[i][j] = '*';    /* create map border*/
            }else if( map->mapArray[i][j] == 0){
                gameState->gameMap[i][j] = ' ';    /* empty space */
            }else if( map->mapArray[i][j] == 1){
                gameState->gameMap[i][j] = '.';    /* road */
            }else if ( map->mapArray[i][j] == 2){
                if (blank_bool == 1){
                    gameState->gameMap[i][j] = '.';
                }
                else{
                    gameState->gameMap[i][j] = '>';    /* car facing right */
                }
                
                car->carRow = i;
                car->carCol = j;
            }else if ( map->mapArray[i][j] == 3){
                /* If we want to generate a blank board of the non-moving parts: */
                if (blank_bool == 1){
                    /* don't print the player, print a blank space instead*/
                    /* assumes that the player starts on a blank spot. */
                    gameState->gameMap[i][j] = ' ';
                }
                else{
                    gameState->gameMap[i][j] = 'P';
                }
                gameState->playerRow = i;
                gameState->playerCol = j;    /* player */
            }else if ( map->mapArray[i][j] == 4){
                gameState->gameMap[i][j] = 'G';
                gameState->goalRow = i;
                gameState->goalCol = j;    /* goal */
            }
        }
    }



}

int updateGame(char move, Map* map, GameState * blankState, GameState* gameState, Car* car, Stack* stack, int directions[4][2],char carChar) {
    

    int i,j;

    int deadplayer;

    int newPlayerRow, newPlayerCol;

    int finished_flag;


    newPlayerRow = gameState->playerRow;
    newPlayerCol = gameState->playerCol;

    finished_flag = 0;

    if(move  ==  'u'){
        gameState = pop(stack);
    }

    if(move != 'u'){
        switch(move) {
            case 'w':
                newPlayerRow --;
                break;
            case 'a':
                newPlayerCol --;
                break;
            case 's':
                newPlayerRow ++;
                break;
            case 'd':
                newPlayerCol ++;
                break;
        }

        
        /* silly code to copy each character of the map to the other one*/
        for(i=0; i < map->row; i++){
            for(j=0; j < map->col; j++){
                gameState->gameMap[i][j] = blankState->gameMap[i][j];
            }
        }

    
        /*every thing that moves moves in the below block*/
        if (newPlayerRow > 0 && newPlayerRow < map->row - 1 && newPlayerCol > 0 && newPlayerCol < map->col -1){
            gameState->playerRow = newPlayerRow;
            gameState->playerCol = newPlayerCol;

            gameState->gameMap[newPlayerRow][newPlayerCol] = 'P';

        

            deadplayer = moveCar(car, map, gameState, blankState, directions, carChar);

            if (gameState->playerRow == gameState->goalRow && gameState->playerCol == gameState -> goalCol){
                
                printf("you win!");
                finished_flag = endGame();
            }

            if(deadplayer){
                gameState->gameMap[newPlayerRow][newPlayerCol] = 'X';
                printf("you lose!");
                finished_flag = endGame();
            }
            push(stack, gameState);
            
        }
    }
    return finished_flag;
}

int endGame() {
    int gameOverflag = 1;
    return gameOverflag;
}

void clearGame(Map* map, GameState* gameState, GameState* blankstate, Car* car) {
    int i;
    if (gameState) {
        printf("gameState free\n");
        for (i = 0; i < map->row; i++) {
            free(gameState->gameMap[i]);
        }
        free(gameState->gameMap);
        
    }

    if (blankstate) {
        printf("blankstate free\n");
        for (i = 0; i < map->row; i++) {
            free(blankstate->gameMap[i]);
        }
        free(blankstate->gameMap);
        
    }

    if (map) {
        printf("map free\n");
        for (i = 0; i < map->row; i++) {
            free(map->mapArray[i]);
        }
        free(map->mapArray);
        
    }

    if (car) {
        printf("car free\n");
        
    }
}


int printGame(Map* map, GameState* gameState) {
    int i, j;
    for(i = 0; i < map->row; i++){
        for(j = 0; j < map->col; j++){
            printf("%c", gameState->gameMap[i][j]);
        }
        printf("\n");
    }
    printf("try to reach the goal 'G'\n");
    printf("W to move up\n");
    printf("A to move left\n");
    printf("D to move right\n");
    printf("S to move down\n");
    printf("U to undo last move\n");
    return 0;
}