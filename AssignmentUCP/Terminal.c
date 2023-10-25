#include <stdio.h>
#include "Terminal.h"
#include "terminalInput.h"

/* Function to clear the terminal screen */
void clearTerminal() {
    /* Use ANSI escape sequences to clear the screen */
    printf("\033[H\033[J");
    fflush(stdout);
}

/* Function to read user input character*/
char getUserMove() {
    char move;
    disableBuffer();
    scanf(" %c", &move); /* Read a single character (ignores leading whitespace)*/
    enableBuffer();
    return move;
}

/* Function to clean up terminal-related resources (if necessary)*/
void cleanupTerminal() {
    /* No cleanup needed in this simple implementation*/
}
