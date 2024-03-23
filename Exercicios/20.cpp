#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

/* 20. Fa�a um programa que leia do usu�rio dois n�meros X e Y tal que Y >= X. Fa�a com que o programa imprima todos
os n�meros primos existentes entre X e Y, inclusive. */

int main(){

	int x, y, primo;
	
    printf("Digite dois numeros X e Y tal que Y >= X (digite um numero negativo para sair):\n");
	do{
		scanf(" %d %d", &x, &y);
		
		if (x >= 0 && y >= 0 && y < x)
            printf("Erro: Y deve ser maior ou igual a X.\n\n");
	
		for (int i = x; i <= y; i++) {
	        int primo = 1; // Consideramos inicialmente que o n�mero � primo
	
	        if (i <= 1) {
	            primo = 0; // N�meros zero e 1 n�o s�o primos
	        } else {
	            for (int j = 2; j * j <= i; j++) {
	                if (i % j == 0) {
	                    primo = 0; // N�o � primo, encontrado divisor
	                    break; // N�o � necess�rio verificar mais divisores
	                }
	            }
	        }
	
	        if (primo == 1)
	            printf("%d ", i);
	    }
	    
		printf("\n\n");

			
	} while (x >= 0 && y >= 0); // Repete at� que ambos X e Y sejam negativos

	
	return 0;
}

