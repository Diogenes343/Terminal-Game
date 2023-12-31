#ifndef CARMOVEMENT_H
#define CARMOVEMENT_H

#include "game.h"
#include "fileReader.h"

struct Car;
struct Map;
struct GameState;

int moveCar(Car* car, Map* map, GameState* gameState, GameState* blankstate, int directions[4][2],char carChar);

#endif
