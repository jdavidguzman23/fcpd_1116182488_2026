/**
 * @file ce_07_producto_escalar_secuencial.c
 * @brief Sequential vector dot product with timing.
 * @author Juan Guzman
 * @date 2026-09-30
 */

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 30000000L

int main(void) {
    double *a = (double *)malloc(N * sizeof(double));
    double *b = (double *)malloc(N * sizeof(double));

    if (a == NULL || b == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        free(a);
        free(b);
        return 1;
    }

    for (long i = 0; i < N; i++) {
        a[i] = 2.0;
        b[i] = 3.0;
    }

    double dot = 0.0;

    double start = omp_get_wtime();
    for (long i = 0; i < N; i++) {
        dot += a[i] * b[i];
    }
    double elapsed = omp_get_wtime() - start;

    printf("Dot Product Result: %.2f (Expected: %.2f)\n", dot, (double)N * 6.0);
    printf("Sequential Time: %.6f seconds\n", elapsed);

    free(a);
    free(b);
    return 0;
}