#include <stdio.h>
#include <stdlib.h>
#include "carMovement.h"
#include "fileReader.h"
#include "game.h"
#include "Terminal.h"


 
int main(int argc, char *argv[]) {
    
    if (argc != 2) {
        printf("Usage: %s <map_file>\n", argv[0]);
        return 1;
    }

    GameState gameState;
    GameState blankState;

    Map map;
    Car car;
    Car blank_car;
    char move;
    int finished;
    int valid_map;
    int directions[4][2];
    char carChar;
    car.carDirection = 0;
    
    /*add more arrays*/

    const char *mapFileName = argv[1];

    valid_map = getMap(&map, mapFileName);


    if (valid_map != 0) {
        printf("Error reading map file: %s\n", mapFileName);
        return 1;
    }
    


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
        clearTerminal();
        printGame(&map, &gameState);
        move = getUserMove();
        switch(car.carDirection) {
            case 0: /*Right*/
                directions[0][0] = 0; directions[0][1] = 1;  
                directions[1][0] = 1; directions[1][1] = 0;  
                directions[2][0] = -1; directions[2][1] = 0; 
                directions[3][0] = 0; directions[3][1] = -1;
                carChar = '>';
                break;
            case 1: /*down*/
                directions[0][0] = 1; directions[0][1] = 0;  
                directions[1][0] = 0; directions[1][1] = -1; 
                directions[2][0] = 0; directions[2][1] = 1; 
                directions[3][0] = -1; directions[3][1] = 0;
                carChar = 'v';  
                break;
            case 2: /*Left*/
                directions[0][0] = 0; directions[0][1] = -1; 
                directions[1][0] = -1; directions[1][1] = 0; 
                directions[2][0] = 1; directions[2][1] = 0;  
                directions[3][0] = 0; directions[3][1] = 1; 
                carChar = '<'; 
                break;
            case 3: /*up*/
                directions[0][0] = -1; directions[0][1] = 0; 
                directions[1][0] = 0; directions[1][1] = 1;  
                directions[2][0] = 0; directions[2][1] = -1;  
                directions[3][0] = 1; directions[3][1] = 0; 
                carChar = '^';
                break;
            default:
                /*defult*/
                directions[0][0] = 0; directions[0][1] = 1;  
                directions[1][0] = 1; directions[1][1] = 0;  
                directions[2][0] = 0; directions[2][1] = -1; 
                directions[3][0] = -1; directions[3][1] = 0;
                carChar = '>';
                break;
    }

        finished = updateGame(move, &map, &blankState, &gameState, &car, directions, carChar);
    }

    clearGame(&map, &gameState, &blankState, &car);

    return 0;
    /* game clean up*/
}