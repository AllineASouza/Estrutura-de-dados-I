#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

/* 7. Fa�a um programa que receba do usu�rio o comprimento de tr�s retas. O programa deve informar ao usu�rio se �
poss�vel ou n�o formar um tri�ngulo com essas retas.*/

int main(){
	
	int a, b, c;
	
	printf("Digite os valores para A, B e C:\n");
	scanf(" %d %d %d", &a, &b, &c);
	
	if(a + b > c && a + c > b && b + c > a)
		printf("Formam um triangulo.\n");
	else
		printf("Nao formam um triangulo!\n");

	return 0;
}

