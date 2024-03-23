#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

/* 20. Faça um programa que leia do usuário dois números X e Y tal que Y >= X. Faça com que o programa imprima todos
os números primos existentes entre X e Y, inclusive. */

int main(){

	int x, y, primo;
	
    printf("Digite dois numeros X e Y tal que Y >= X (digite um numero negativo para sair):\n");
	do{
		scanf(" %d %d", &x, &y);
		
		if (x >= 0 && y >= 0 && y < x)
            printf("Erro: Y deve ser maior ou igual a X.\n\n");
	
		for (int i = x; i <= y; i++) {
	        int primo = 1; // Consideramos inicialmente que o número é primo
	
	        if (i <= 1) {
	            primo = 0; // Números zero e 1 não são primos
	        } else {
	            for (int j = 2; j * j <= i; j++) {
	                if (i % j == 0) {
	                    primo = 0; // Não é primo, encontrado divisor
	                    break; // Não é necessário verificar mais divisores
	                }
	            }
	        }
	
	        if (primo == 1)
	            printf("%d ", i);
	    }
	    
		printf("\n\n");

			
	} while (x >= 0 && y >= 0); // Repete até que ambos X e Y sejam negativos

	
	return 0;
}

