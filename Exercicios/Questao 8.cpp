/* 5. Faça um programa que leia, em formato de string, um valor 
binário. O programa deve imprimir o número lido no formato decimal 
correspondente. Exemplo: 10110 == 22*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
	
	char numero[20];
	scanf("%s", &numero);

	int tam, novoValor = 0;
	tam = strlen(numero); 
	
	for (int i = tam-1; i >= 0; i--) {
		if (numero[i] == '1') {
			novoValor += pow(2,tam-1-i);
		}
	}
	printf("Decimal: %i", novoValor);
	
	return 0;
}

	
