/**
 * @file ec_01_acceso_arreglo.c
 * @brief Accessing array elements using pointer arithmetic.
 * @author Juan David Guzman
 * @date 2026-09-30
 */

#include <stdio.h>

#define SIZE 10

int main(void) {
    int arr[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *ptr = arr; 

    printf("Array elements accessed via pointer arithmetic:\n");
    for (int i = 0; i < SIZE; i++) {
        
        printf("Element %d: %d (Address: %p)\n", i, *(ptr + i), (void *)(ptr + i));
    }

    return 0;
}