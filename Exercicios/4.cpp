#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>


/* 4. Faça um programa que leia um valor inicial N e uma razão R. Imprima uma sequência em P.A. contendo 10 valores,
e uma sequência em P.G. contendo 10 valores. P.Ex.: N == 3 e R == 2.
PA = 3 - 5 - 7 - 9 - 11 - 13 - 15 - 17 - 19 - 21
PG = 3 - 6 - 12 - 24 - 48 - 96 - 192 - 384 - 768 - 1536 */

int main(){

	int n, r, i, pa, pg;

	printf("digite um numero: ");
	scanf(" %d", &n);
	printf("digite um numero: ");
	scanf(" %d", &r);	
	
	pa = n;
	pg = n;
	
	printf("\nPA:");
	for(int i = 0; i <= 9; i++){
		printf(" %d - ", pa);
		pa += r;
	}
	
	printf("\n\nPG:");
	for(int i = 0; i <= 9; i++){
		printf(" %d - ", pg);
		pg *= r;
	}
	
	return 0;
	}

