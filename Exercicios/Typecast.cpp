#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

/* Typecast
Faça um programa que leia dois valores inteiros X e Y, tal que Y seja maior que X. 
Apresente o valor da divisão de X por Y.*/

int main(){

	int x, y;
	
	printf("Digite 2 valores inteiros, tal que o segundo numero seja maior: ");
	scanf(" %d %d", &x, &y);
	
	float z = (float) x / y;
	
	printf("O valor da divisao e: %.2f", z);

	return 0;
}



