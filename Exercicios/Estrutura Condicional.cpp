#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

/* Estrutura Condicional
Faça um programa que leia 3 variáveis de valor inteiro e imprima-os em ordem crescente.*/

int main(){
	
	int aux, n1, n2, n3;
 	
 	printf("Digite 3 numeros inteiros: ");
 	scanf(" %d %d %d", &n1, &n2, &n3);
 	
	if (n1 > n2) { 
	  aux = n1;
	  n1  = n2; 
	  n2  = aux;
	}

	if (n2 <= n3) 
	    printf("A ordem crescente: %d %d %d\n", n1, n2, n3); 
		
		else if (n1 <= n3) 
			printf("A ordem crescente: %d %d %d\n", n1, n3, n2);
			
			else
				printf("A ordem crescente: %d %d %d\n", n3, n1, n2);
				
	return 0;
}

