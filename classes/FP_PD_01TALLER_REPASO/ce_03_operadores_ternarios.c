/**
 * @file ce_03_operadores_ternarios.c
 * @brief Find the largest and smallest of three numbers using ternary operators.
 * @author Juan Guzman
 * @date 2026-09-12
 */


 #include <stdio.h>


int find_max(int a, int b, int c){
    int max =(a>b) ? a:b;
    max=(max>c)?max:c;

    return max;


}

int find_min(int a, int b, int c){
    int min =(a<b) ? a:b;
    min=(min<c)?min:c;

    return min;
}



int main(){
    int a=23, b=34, c=54;

    int max=find_max(a,b,c);
    int min= find_min(a,b,c);

    printf("the largest number is: %d\n", max);
    printf("the smallest number is: %d\n", min);
    return 0;
}