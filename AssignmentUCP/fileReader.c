#include <stdio.h>
#include <stdlib.h>
#include "fileReader.h"

int getMap(Map *map, const char *filepath) {
    FILE *fp;
    int **mapArray;
    int row, col;
    int error = 0;
    int i, j, k;

    if (map == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        error = 11;
    }

    fp = fopen(filepath, "r");
    if (fp == NULL) {
        fprintf(stderr, "File does not exist.\n");
        error = 12;
    }

    if (fscanf(fp, "%d %d", &row, &col) != 2) {
        fprintf(stderr, "File format error 01.\n");
        fclose(fp);
        error = 13;
    }

    mapArray = (int **)malloc(sizeof(int *) * row);
    if (mapArray == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        fclose(fp);
        error = 14;
    }

    for (i = 0; i < row; i++) {
        mapArray[i] = (int *)malloc(sizeof(int) * col);
        if (mapArray[i] == NULL) {
            fprintf(stderr, "Memory allocation error.\n");
            fclose(fp);

            for (j = 0; j < i; j++) {
                free(mapArray[j]);
            }
            free(mapArray);
            error = 15;
        }
    }

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (fscanf(fp, "%d", &mapArray[i][j]) != 1) {
                fprintf(stderr, "File format error 02.\n");
                fclose(fp);

                for (k = 0; k < row; k++) {
                    free(mapArray[k]);
                }
                free(mapArray);
                error = 16;
            }
        }
    }

    map->row = row;
    map->col = col;
    map->mapArray = mapArray;

    fclose(fp);

    return error;
}
