#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

/* 1. Fa�a um programa em C que leia do usu�rio um n�mero inteiro X. Ap�s isto, o
programa deve imprimir uma quantidade X de n�meros aleat�rios entre 0 e 50. */

int main(){

	srand(time(NULL));
	
	int x;
	
	printf("Digite um numero inteiro: ");
 	scanf(" %d", &x);
	
	for (int i = 0; i < x; i++) {
        int num_aleatorio = rand() % 51; // Gera um n�mero aleat�rio entre 0 e 50
        printf("%d\n", num_aleatorio);
    }

return 0;
}

