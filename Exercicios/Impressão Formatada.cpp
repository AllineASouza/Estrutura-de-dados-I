#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

/* Impressão Formatada
Faça um programa que leia um valor fracionado F e um valor inteiro X. 
Imprima o produto das duas variáveis com exatamente 3 casas decimais.*/

int main(){

	int x;
	float f;
	
	printf("Digite um numero inteiro: ");
	scanf(" %d", &x);
	printf("Digite um numero fracionado: ");
	scanf(" %f", &f);
	
	printf("o produto dos numeros %d e %.1f e: %.3f", x,f, (x*f));	

	return 0;
	}

