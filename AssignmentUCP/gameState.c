/*
#include <stdio.h>
#include <stdlib.h>
#include"gameState.h"

#define ARRAY_SIZEX 2
#define ARRAY_SIZEY 2

struct gameState {
    int mapArray[ARRAY_SIZEX][ARRAY_SIZEY];
    struct gameState* next;
};

struct gameState* createArrayNode(int arr[ARRAY_SIZEX][ARRAY_SIZEY]) {
    struct gameState* newNode = (struct gameState*)malloc(sizeof(struct gameState));
    int i, j;
    if (newNode == NULL) {
        printf("Memory allocation error.\n");
        return NULL;
    }
    for (i = 0; i < ARRAY_SIZEX; i++) {
        for (j = 0; j < ARRAY_SIZEY; j++) {
            newNode->mapArray[i][j] = arr[i][j];
        }
    }
    newNode->next = NULL;
    
    return newNode;
}

void insertArrayNode(struct gameState** newNode, int arr[ARRAY_SIZEX][ARRAY_SIZEY]) {
    struct gameState* temp = createArrayNode(arr);

    if (*newNode == NULL) {
        *newNode = temp;
    } else {
        struct gameState* current = *newNode;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = temp;
    }
}

void printArrayNode(struct gameState* newNode) {
    while (newNode != NULL) {
        for (int i = 0; i < ARRAY_SIZEX; i++) {
            for (int j = 0; j < ARRAY_SIZEY; j++) {
                printf("%d ", newNode->mapArray[i][j]);
            }
            printf("\n");
        }
        newNode = newNode->next;
    }
}

void addGameState(char** gameMap) {
    GameState* gameState = (GameState*)malloc(sizeof(GameState));
    gameState->gameMap = gameMap;
    
    gameState->next = NULL;

    if (gameStateHead == NULL) {
        gameStateHead = gameState;
    } else {
        GameState* gameStatePtr = gameStateHead;
        while (gameStatePtr->next != NULL) {
            gameStatePtr = gameStatePtr->next;
        }
        gameStatePtr->next = gameState;
    }
}

void undoGameState(char** gameMap) {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
    if (GameState->next != NULL) {
        gameState* temp = currentGameState;
        currentGameState = gameState->next;
        
        for (int i = 0; i < Map->col; i++) {
            for (int j = 0; j < Map->row; j++) {
                free(gameMap[i][j])
            }
        }
    }
    free(temp->gameMap);
    free(temp);
}
/*
int main() {
    struct gameState* newNode = NULL;
    int arr[ARRAY_SIZEX][ARRAY_SIZEY] = {
        {1, 2},
        {3, 4}
    };
    insertArrayNode(&newNode, arr);
    
    int arr2[ARRAY_SIZEX][ARRAY_SIZEY] = {
        {5, 6},
        {7, 8}
    };
    insertArrayNode(&newNode, arr2);

    printArrayNode(newNode);

    // Free memory
    while (newNode != NULL) {
        struct gameState* temp = newNode;
        newNode = newNode->next;
        free(temp);
    }

    return 0;
}
*/
