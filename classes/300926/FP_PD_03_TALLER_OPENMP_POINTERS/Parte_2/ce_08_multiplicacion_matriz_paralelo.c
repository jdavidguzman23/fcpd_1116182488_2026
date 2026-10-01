/**
 * @file ce_08_multiplicacion_matriz_paralelo.c
 * @brief Parallel square matrix multiplication (OpenMP) with rows-per-thread logging and timing.
 * @author Juan Guzman
 * @date 2026-09-30
 */

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 1000

double** allocate_matrix(int size) {
    double **mat = (double **)malloc(size * sizeof(double *));
    if (mat == NULL) return NULL;
    for (int i = 0; i < size; i++) {
        mat[i] = (double *)malloc(size * sizeof(double));
        if (mat[i] == NULL) return NULL;
    }
    return mat;
}

void free_matrix(double **mat, int size) {
    for (int i = 0; i < size; i++) free(mat[i]);
    free(mat);
}

int main(void) {
    double **A = allocate_matrix(N);
    double **B = allocate_matrix(N);
    double **C = allocate_matrix(N);

    if (A == NULL || B == NULL || C == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = 1.0;
            B[i][j] = 2.0;
            C[i][j] = 0.0;
        }
    }

    int max_threads = omp_get_max_threads();
    int *rows_done = (int *)calloc(max_threads, sizeof(int));

    double start = omp_get_wtime();
    #pragma omp parallel for schedule(static)
    for (int i = 0; i < N; i++) {
        rows_done[omp_get_thread_num()]++;
        for (int j = 0; j < N; j++) {
            double sum = 0.0;
            for (int k = 0; k < N; k++) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
    double elapsed = omp_get_wtime() - start;

    for (int t = 0; t < max_threads; t++) {
        printf("Hilo %d calculo %d filas\n", t, rows_done[t]);
    }

    int correct = 1;
    for (int i = 0; i < N && correct; i++) {
        for (int j = 0; j < N; j++) {
            if (C[i][j] != (double)N * 2.0) {
                correct = 0;
                break;
            }
        }
    }

    printf("Matrix Size: %d x %d\n", N, N);
    printf("Result Correct: %s\n", correct ? "YES" : "NO");
    printf("Parallel Time: %.6f seconds\n", elapsed);

    free(rows_done);
    free_matrix(A, N);
    free_matrix(B, N);
    free_matrix(C, N);
    return 0;
}