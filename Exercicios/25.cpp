#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

/* 2. Fa�a um programa que leia do usu�rio um s�mbolo (caractere) e retorne
o c�digo ASCII correspondente.*/


int main(){

	char x;
	
	printf("\nDigite um simbolo(caractere): ");
	scanf(" %c", &x);
	
	printf("\nO codigo ASCII '%c' e %d.\n", x, x);
   
	return 0;
	}

