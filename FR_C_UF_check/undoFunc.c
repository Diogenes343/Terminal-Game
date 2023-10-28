#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "undoFunc.h"


/*Function to create a new node with the given data.*/
Node* createNode(GameState* gameState) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode -> gameState = *gameState;
    newNode->next = NULL;
    return newNode;
}

/*Function to initialize an empty stack.*/
void initStack(Stack* stack) {
    stack->top = NULL;
}

/*Function to push an element onto the stack.*/
void push(Stack* stack, GameState* gameState) {
    Node* newNode = createNode(gameState);
    newNode->next = stack->top;
    stack->top = newNode;
}

/*Function to pop an element from the stack.*/
GameState* pop(Stack* stack) {
    Node* temp = stack->top;
    if (stack->top == NULL) {
        printf("Stack is empty.\n");
        exit(1);
    }

    
    stack->top = stack->top->next;

    /* Check if there is a previous node. */
    if (stack->top != NULL) {
        GameState* gameState = &(stack->top->gameState); /* Retrieve a pointer to the GameState from the new top node. */
        free(temp);
        return gameState; /* Return the pointer to the GameState of the previous node. */
    } else {
        /* If there's no previous node, just return the pointer to the GameState of the popped node. */
        GameState* gameState = &(temp->gameState);
        free(temp);
        return gameState;
    }
}

void freeStack(Stack* stack) {
    while (!isEmpty(stack)) {
        pop(stack);
    }
}





/*Function to check if the stack is empty.*/
int isEmpty(Stack* stack) {
    return stack->top == NULL;
}
