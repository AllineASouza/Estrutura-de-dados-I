#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

/* 11. Faça um programa que imprima na tela um triângulo equilátero formado por símbolos *.
Este triângulo deve ter altura de N linhas (N >= 2 e deve ser informado pelo usuário no início da execução). */


int main( ){
  
  int n;
  
  printf("Digite numero de linhas: ");
  scanf(" %d", &n);
 
   for (int i = 1; i <= n; i++) {
        // Imprime os espaços em branco antes dos asteriscos
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }
        // Imprime os asteriscos
        for (int c = 1; c <= i * 2 - 1; c++) {
            printf("*");
        }
        printf("\n");
    }

return 0;}
  

