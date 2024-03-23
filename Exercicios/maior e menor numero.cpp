#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

/* Laço de Repetição
Faça um programa que leia 10 valores inteiros e imprima o maior e o menor valor inseridos.*/

int main(){
	 
	int maior, menor, a;

	for (int i = 0; i < 10; i++){
	
		printf("Digite um numero: ");
		scanf(" %d", &a);
		
		if (a < menor  || i == 0 )
			menor = a;
		
		if (a > maior  || i == 0 )
			maior = a;	
	}

	printf("\nO menor numero entrado e: %d", menor);
	printf("\nO maior numero entrado e: %d", maior);
		
	return 0;
}


	






