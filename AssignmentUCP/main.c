#include <stdio.h>
#include <stdlib.h>
#include "carMovement.h"
#include "fileReader.h"
#include "game.h"
#include "Terminal.h"


 
int main() {

    GameState gameState;
    GameState blankState;

    Map map;
    Car car;
    Car blank_car;
    char move;
    int finished;
    int valid_map;
    /*int directions[4][2];*/
    int directions[4][2] = {
        {0, 1},  /* Right */
        {1, 0},  /* Down */
        {0, -1}, /* Left */
        {-1, 0}  /* Up */
    };

    valid_map = getMap(&map, "map.txt");
    



    if( valid_map != 0){
        printf("Error reading map file.\n");
        return 1;
    }

    /* I added this boolean, which doesn't include the car */
    /* This is useful for updating the player and car positions */
    intialiseGame(&map, &gameState, &car, 0);

    blank_car.carRow = 0;
    blank_car.carCol = 0;
    
    
    intialiseGame(&map, &blankState, &blank_car, 1);
    blankState.playerRow = -1;
    blankState.playerCol = -1;
    
    finished = 0;

    /* check for valid map*/
    while(finished == 0) {
        /*clearTerminal();*/
        printGame(&map, &gameState);
        move = getUserMove();
        finished = updateGame(move, &map, &blankState, &gameState, &car, directions);
    }

    clearGame(&map, &gameState, &car);
    return 0;
    /* game clean up*/
}