#include <stdio.h>
#include <stdlib.h>
#include "carMovement.h"
#include "fileReader.h"
#include "game.h"
#include "Terminal.h"


 
int main() {

    GameState gameState;
    Map map;
    Car car;
    char move;

    if( getMap(&map, "map.txt") != 0){
        printf("Error reading map file.\n");
        return 1;
    }

    intialiseGame(&map, &gameState, &car);

    /* check for valid map*/
    while(!endGame()) {
        clearTerminal();
        printGame(&map, &gameState);
        move = getUserMove();
        updateGame(move, &map, &gameState, &car);
    }
    clearGame(&map, &gameState, &car);
    return 0;
    /* game clean up*/
}