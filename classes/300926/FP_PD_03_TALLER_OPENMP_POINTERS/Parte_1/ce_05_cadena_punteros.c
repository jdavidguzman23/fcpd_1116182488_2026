/**
 * @file ec_cadena_punteros.c
 * @brief Traversing a null-terminated string using a pointer.
 * @author Juan David Guzman
 * @date 2026-09-30
 */

#include <stdio.h>

int main(void) {
    char str[] = "OpenMP & Pointers";
    char *ptr = str;

    printf("Character | Memory Address\n");
    printf("---------------------------\n");

    while (*ptr != '\0') {
        printf("    '%c'   | %p\n", *ptr, (void *)ptr);
        ptr++; 
    }

    return 0;
}