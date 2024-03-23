#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

/*Representação de Dados
Faça um programa que leia um símbolo numérico (entre '0' e '9') em formato CHAR. 
Faça a conversão e impressão do mesmo valor em formato INT.*/

int main(){

	char x;
	
	printf("Digite um simbolo numerico entre 0 e 9: ");
	scanf(" %c", &x);
	
	printf("\nValor do simbolo numerico em char e: %c\n\nValor numerico em int e: %d", x, x-'0');

	return 0;
}

