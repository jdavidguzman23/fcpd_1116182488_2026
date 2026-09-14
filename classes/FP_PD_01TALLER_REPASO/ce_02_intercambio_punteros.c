/**
 * @file ce_02_intercambios_punteros.c
 * @brief swapping values ​​using pointers
 * @author Juan Guzman
 * @date 2026-09-12
 */

 #include <stdio.h>

 void swap(int *x, int *y){
    int temp;
    temp= *x;
    *x=*y;
    *y=temp;

 }


 int main(){
    int x=23;
    int y=54;

    printf("before: x= %d, y = %d\n", x,y);

    swap(&x,&y);

    printf("after: %d, y=%d\n", x,y);

 

    return 0;
 }


