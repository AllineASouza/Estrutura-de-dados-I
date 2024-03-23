#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

/* La�o de Repeti��o
Fa�a um programa que leia do usu�rio um valor inteiro X. Fa�a a impress�o decrescente de todos os valores pares at� X.*/

int main(){

    int x;
    
    printf("Digite um numero inteiro: ");
    scanf(" %d", &x);

    // Enquanto x for maior ou igual a zero, continua o loop
    while (x >= 0) {
        // Verifica se x � par
        if (x % 2 == 0) {
            // Se x for par, imprime-o
            printf("\n%d", x);
        }
        // Decrementa x para o pr�ximo n�mero
        x--;
    }
    
    return 0;
}
	


