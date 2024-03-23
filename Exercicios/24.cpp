#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

/* 4. Faça um programa que leia 3 valores (inteiros e positivos) de retas
e verifique se eles conseguem formar ou não um triângulo.*/

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

