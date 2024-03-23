#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

/* La�o de Repeti��o
Fa�a um programa que leia v�rios n�meros inteiros indefinidamente, at� que o n�mero lido seja negativo. 
Apresente a soma dos n�meros, quantidade lida e m�dia aritm�tica.*/


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




