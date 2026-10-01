/**
 * @file ec_matriz_punteros.c
 * @brief Dynamic allocation and traversal of a 3x3 matrix using pointers to pointers.
 * @author Juan Guzman 
 * @date 2026-09-30
 */

#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

int main(void) {

    int **matrix = (int **)malloc(ROWS * sizeof(int *));
    if (matrix == NULL) {
        fprintf(stderr, "Memory allocation failed for rows.\n");
        return 1;
    }

    for (int i = 0; i < ROWS; i++) {
        *(matrix + i) = (int *)malloc(COLS * sizeof(int));
        if (*(matrix + i) == NULL) {
            fprintf(stderr, "Memory allocation failed for row %d.\n", i);
            return 1;
        }
    }

    
    int val = 1;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            *(*(matrix + i) + j) = val++;
        }
    }

  
    printf("3x3 Matrix contents (accessed via *(*(matrix + i) + j)):\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d\t", *(*(matrix + i) + j));
        }
        printf("\n");
    }


    for (int i = 0; i < ROWS; i++) {
        free(*(matrix + i));
    }
    free(matrix);

    return 0;
}