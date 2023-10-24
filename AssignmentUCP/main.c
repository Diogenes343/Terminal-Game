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
    int keep_going;
    int valid_map;
    
    valid_map = getMap(&map, "map.txt");

    if( valid_map != 0){
        printf("Error reading map file.\n");
        return 1;
    }

    intialiseGame(&map, &gameState, &car);
    keep_going = endGame();
    /* check for valid map*/
    while(keep_going) {
        clearTerminal();
        printGame(&map, &gameState);
        move = getUserMove();
        keep_going = updateGame(move, &map, &gameState, &car);
    }
    clearGame(&map, &gameState, &car);
    return 0;
    /* game clean up*/
}