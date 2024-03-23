#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

/* 15. Fa�a um programa que receba um n�mero e verifique se ele � ou n�o um n�mero perfeito. Um n�mero � perfeito 
quando a soma de todos os seus divisores inteiros � excluindo ele mesmo � � igual ao pr�prio n�mero. 
Ex: 28 = 1 + 2 + 4 + 7 + 14.*/

int main() {
  
	int n, soma;
	 
	printf("Digite um numero inteiro positivo: ");
	scanf("%d", &n);
	
	soma = 0;
	
	for (int i = 1; i < n; i++){
		if (n % i == 0)
	  		soma += i;
	}
	
	if (n == soma)
		printf("O numero %d e' perfeito\n", n);
	else 
		printf("O numero %d nao e' perfeito\n", n);

	return 0;
}

