#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

/* Laço de Repetição
Faça um programa que leia um valor inteiro X e imprima a tabuada de multiplicação deste número (0 a 100). */

int main(){

	int x;
	
	printf("Digite um numero inteiro: ");
	scanf(" %d", &x);
	
	for(int a = 0; a <= 100; a++)
		printf("%d x %d\t => %d\n", x, a, (x*a));

	return 0;
}

