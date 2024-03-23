#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

/* 5. Faça um programa que leia um valor inteiro N não-negativo. O programa deve calcular e imprimir o valor de N!
N Fatorial. P.Ex.: 6! == 720; 9! == 362880.*/

int main(){

	int n, fat = 1;
	
	printf("Informe o valor de n: ");
	scanf(" %d", &n);
	
	for(int i = n; i > 1; i--){
		fat *= i;
	}
	
	printf("\nFatorial de %d! == %d\n", n, fat);
	
	return 0;
}

