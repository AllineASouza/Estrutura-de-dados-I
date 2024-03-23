#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

/* Laço de Repetição
Faça um programa que leia vários números inteiros indefinidamente, até que o número lido seja negativo. 
Apresente a soma dos números, quantidade lida e média aritmética.*/


int main(){

	int x, i, soma;
	float media = 0;
	
	i = soma = 0;
	
	printf("Informe um numero negativo para encerar.\n\n");
	
	do{
		printf("Digite um numero: ");
		scanf(" %d", &x);
		
		if( x >= 0 ){
			soma += x;
			i++;
			media = (float) soma / i;	
		}
			
	}while (x >= 0);
		
	printf("\nSoma: %d\n", soma);
	printf("\nQuantidade lida: %d\n", i);
	printf("\nMedia: %.3f", media);
	
	return 0;
}




