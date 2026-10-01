/**
 * @file ce_06_suma_arreglo_paralelo.c
 * @brief Parallel array sum using OpenMP reduction, with thread logging and timing.
 * @author Juan Guzman
 * @date 2026-09-30
 */

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 100000000L

int main(void) {
    int *arr = (int *)malloc(N * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    for (long i = 0; i < N; i++) {
        arr[i] = 1;
    }

    long long sum = 0;

    double start = omp_get_wtime();
    #pragma omp parallel reduction(+:sum)
    {
        #pragma omp critical
        printf("Hilo %d de %d participando\n", omp_get_thread_num(), omp_get_num_threads());

        #pragma omp for
        for (long i = 0; i < N; i++) {
            sum += arr[i];
        }
    }
    double elapsed = omp_get_wtime() - start;

    printf("Parallel Sum: %lld (Expected: %ld)\n", sum, N);
    printf("Parallel Time: %.6f seconds\n", elapsed);

    free(arr);
    return 0;
}