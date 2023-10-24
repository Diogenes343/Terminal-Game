#ifndef CARMOVEMENT_H
#define CARMOVEMENT_H

#include "game.h"
#include "fileReader.h"

struct Car;
struct Map;
struct GameState;

void moveCar(Car* car, Map* map, GameState* gameState);

#endif
