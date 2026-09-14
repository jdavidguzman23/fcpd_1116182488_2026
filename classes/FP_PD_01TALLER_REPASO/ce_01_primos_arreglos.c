/**
 * @file ce_01_primos_arreglos.c
 * @brief Implementation of the prime number exercise using arrays
 * @author Juan Guzman
 * @date 2026-09-12
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

int isPrime(int number) {
    if (number < 2) {
        return 0;
    }

    for (int i = 2; i < number; i++) {
        if (number % i == 0) {
            return 0;
        }
    }

    return 1;
}

int main() {

    int n;
    int array[MAX];
    int primeCount = 0;

    srand(time(NULL));

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid size\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        array[i] = rand() % 100 + 1;
    }

    printf("Array: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);

        if (isPrime(array[i])) {
            primeCount++;
        }
    }

    printf("\nNumber of prime numbers: %d\n", primeCount);

    return 0;
}