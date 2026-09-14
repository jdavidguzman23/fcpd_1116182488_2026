/**
 * @file ce_04_factorial_pariadad.c
 * @brief Calculate the factorial of a number and determine whether the result is even or odd.
 * @author Juan Guzman
 * @date 2026-09-12
 */

 #include<stdio.h>


 int factorial(int n){

    int factorial=1;
    for (int i = n; i >=1; i--){
      factorial=factorial*i;

    }
    return factorial;

    
 }




 void factorial_and_parity(){

 }

 int main(){
   int facto = factorial(5);

    printf("Factorial is: %d\n", facto);

    if (facto % 2 == 0) {
        printf("The factorial is par\n");
    } else {
        printf("The factorial is odd\n");
    }

    return 0;

 }