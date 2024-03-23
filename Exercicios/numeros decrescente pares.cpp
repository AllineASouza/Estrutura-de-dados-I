#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

/* Laço de Repetição
Faça um programa que leia do usuário um valor inteiro X. Faça a impressão decrescente de todos os valores pares até X.*/

int main(){

    int x;
    
    printf("Digite um numero inteiro: ");
    scanf(" %d", &x);

    // Enquanto x for maior ou igual a zero, continua o loop
    while (x >= 0) {
        // Verifica se x é par
        if (x % 2 == 0) {
            // Se x for par, imprime-o
            printf("\n%d", x);
        }
        // Decrementa x para o próximo número
        x--;
    }
    
    return 0;
}
	


