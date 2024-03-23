#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

/* 3. Faça um programa que recebe um caractere minúsculo (a-z) e imprima o
mesmo caractere em maiúsculo. */

int main(){
	
	char caractere, maiusculo;
	
	printf("Digite um caractere minusculo: ");
	scanf("%c", &caractere);
	
//	maiusculo = toupper(caractere); // TOUPPER faz conversão de minusculo para maiusculo / maiusculo para minusculo
									
	printf("Maiusculo e: %c", (caractere - 32));
	
	return 0;
	}

