#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

/* 1. Faça um programa em C que leia do usuário um número inteiro X. Após isto, o
programa deve imprimir uma quantidade X de números aleatórios entre 0 e 50. */

int main(){

	srand(time(NULL));
	
	int x;
	
	printf("Digite um numero inteiro: ");
 	scanf(" %d", &x);
	
	for (int i = 0; i < x; i++) {
        int num_aleatorio = rand() % 51; // Gera um número aleatório entre 0 e 50
        printf("%d\n", num_aleatorio);
    }

return 0;
}

