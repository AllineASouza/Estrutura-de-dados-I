#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

/* 8. Fa�a um programa que gere um n�mero aleat�rio entre 0 e K. O programa deve imprimir o n�mero sorteado e a
quantidade de d�gitos que ele possui (p.ex.: O n�mero 6958 possui 4 d�gitos). */
		
int main(){

	int k, i = 0;
	
	srand(time(NULL));
	printf("digite um numero: ");
	scanf(" %d", &k);
	
	int n = rand() % k;
		printf("\nO numero sorteado foi : %d\n", n);
	
	while(n > 0){
		i++;
		n /= 10;
	} 	
	
	printf("\nO numero sorteado tem %d digito.", i);	 
 
	return 0;
}

