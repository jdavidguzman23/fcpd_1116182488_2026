/**
 * @file ce_06_suma_arreglo_secuencial.c
 * @brief Sequential array sum with timing.
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
    for (long i = 0; i < N; i++) {
        sum += arr[i];
    }
    double elapsed = omp_get_wtime() - start;

    printf("Sequential Sum: %lld (Expected: %ld)\n", sum, N);
    printf("Sequential Time: %.6f seconds\n", elapsed);

    free(arr);
    return 0;
}