#ifndef STACK_H
#define STACK_H

#include "game.h" /* Include game.h to use the existing definition of GameState */

Node* createNode(GameState* gameState);

void freeStack(Stack* stack);

void initStack(Stack* stack);

void push(Stack* stack, GameState* gameState);

GameState* pop(Stack* stack);

int isEmpty(Stack* stack);

#endif /* STACK_H */
