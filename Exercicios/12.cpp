#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

/* 12. Fa�a um programa que receba um n�mero informado pelo usu�rio e imprima a informa��o se este � um 
n�mero primo ou n�o. O programa deve testar v�rios n�meros, at� que o usu�rio digite qualquer valor negativo.*/

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

