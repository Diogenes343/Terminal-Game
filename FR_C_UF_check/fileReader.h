#ifndef FILEREADER_H
#define FILEREADER_H

#include <stdio.h>

typedef struct Map{
    int row;
    int col;
    int **mapArray;
} Map;

int getMap(Map *map, const char *filepath);

#endif
