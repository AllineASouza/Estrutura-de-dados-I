#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

/* 2. Faça um programa que leia um par de valores inteiros (X,Y), tal que, obrigatoriamente Y >= X. O programa deve
calcular e imprimir o valor da soma de todos os números inteiros do intervalo X,Y (inclusive). A operação deve ser
repetida até que os dois valores (X e Y) informados sejam negativos. (P.ex.: (7,11)==45; (53,68)==968).*/

int main(){
	
	int x, y, soma =0;

	printf("Para encerrar o programa os dois valores (X e Y) devem ser negativos");
	
	do{
		printf("\nDigite um numero: ", x); 
		scanf(" %d", &x);
		printf("Digite um numero: ", y);
		scanf(" %d", &y);
		
		 // Verifica se Y é menor que X
        if ( y < x ) {
            printf("Erro: Y deve ser maior ou igual a X.\n");
            continue;
        }
	
		printf("\nA soma dos numeros no intervalos (%d , %d) = %d\n\n", x, y, x+y);
		
	}while(x >= 0 && y >= 0);

	return 0;
}
