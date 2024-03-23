#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

/* 1. Fa�a um programa que leia um n�mero indeterminado de valores inteiros. A leitura somente ser� interrompida
quando o usu�rio informar o valor zero. Valores negativos devem ser ignorados para os c�lculos. O programa deve
gerar os seguintes resultados (ignorando valor 0 e negativos): Soma dos n�meros lidos, M�dia dos n�meros lidos,
Maior valor informado, Menor valor informado, Percentual de n�meros pares e o Percentual de N�meros �mpares.*/

int main(){
   
    int n, i = 0, soma = 0;
    float media = 0, ppar = 0, pimpar = 0;
    int maior = INT_MIN; // Define 'maior' como o menor valor poss�vel para um inteiro
    int menor = INT_MAX; // Define 'menor' como o maior valor poss�vel para um inteiro
	
	printf("Insira um numero negativo para encerrar.\n");
	
	do{
		printf("Digite um numero: ");
		scanf(" %d", &n);

		if (n > 0) {
			
			soma += n;
			i++;
			media = (float) soma / i;
			
			if ( n > maior )
				maior = n;
			
			if ( n < menor )
				menor = n;
			
			if (n % 2 == 0)
				ppar++;
			else
				pimpar++;
		}
	
	}while(n > 0);	
    
	if (i > 0) {
        ppar = (ppar / i) * 100;
        pimpar = (pimpar / i) * 100;
    }

    printf("\nSoma: %d\n", soma);
    printf("Media: %.2f\n", media);
    printf("Maior numero: %d\n", maior);
    printf("Menor numero: %d\n", menor);
    printf("Porcentagem de pares: %.1f%%\n", ppar);
    printf("Porcentagem de impares: %.1f%%\n", pimpar);
	
	return 0;
	}

