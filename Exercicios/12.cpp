#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

/* 12. Faça um programa que receba um número informado pelo usuário e imprima a informação se este é um 
número primo ou não. O programa deve testar vários números, até que o usuário digite qualquer valor negativo.*/

int main(){

int n, i;

	printf("Quando quiser encerrar, digite um numero negativo.\n");
	
	do{
		printf("Digite um numero:  ");
		scanf(" %d", &n);

		if(n<=1){
			printf("Nao e primo\n");
		}else{
			for(i = 2; i < n; i++){
				if(n % i == 0){
					printf("Nao e primo\n");
					break;
				}
			}
			if(i == n){
				printf("E primo\n");
			}
		}
	
	}while( n >= 0 );

	return 0;
}

