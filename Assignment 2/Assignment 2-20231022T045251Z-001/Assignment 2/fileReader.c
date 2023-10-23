#include <stdio.h>
#include <stdlib.h>
#include "fileReader.h"

int getMap(Map *map, const char *filepath) {
    FILE *fp;
    int row, col;

    if (map == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        return 11;
    }

    fp = fopen(filepath, "r");
    if (fp == NULL) {
        fprintf(stderr, "File does not exist.\n");
        return 12;
    }

    if (fscanf(fp, "%d %d", &row, &col) != 2) {
        fprintf(stderr, "File format error 01.\n");
        fclose(fp);
        return 13;
    }

    int **mapArray = (int **)malloc(sizeof(int *) * row);
    if (mapArray == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        fclose(fp);
        return 14;
    }

    for (int i = 0; i < row; i++) {
        mapArray[i] = (int *)malloc(sizeof(int) * col);
        if (mapArray[i] == NULL) {
            fprintf(stderr, "Memory allocation error.\n");
            fclose(fp);

            for (int j = 0; j < i; j++) {
                free(mapArray[j]);
            }
            free(mapArray);
            return 15;
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (fscanf(fp, "%d", &mapArray[i][j]) != 1) {
                fprintf(stderr, "File format error 02.\n");
                fclose(fp);

                for (int k = 0; k < row; k++) {
                    free(mapArray[k]);
                }
                free(mapArray);
                return 16;
            }
        }
    }

    map->row = row;
    map->col = col;
    map->mapArray = mapArray;

    fclose(fp);

    return 0;
}
