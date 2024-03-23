#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

/* 6. Sabia que a sequ�ncia Fibonacci est� ligada intimamente � natureza? Os n�meros da s�rie s�o facilmente
encontrados nos seres vivos e no meio ambiente. Essa s�rie � infinita e se inicia com os valores: 1, 1, 2, 3, 5, 8, 13,
21, 34, (...), onde o pr�ximo valor sempre ser� a soma dos dois valores anteriores.
Fa�a um programa que leia um valor N, e imprima todos N primeiros termos da s�rie Fibonacci.
Ap�s isso, imprima o resultado da divis�o do �ltimo termo pelo pen�ltimo termo.
Repita essa mesma opera��o para diversos valores de N diferentes, e veja o que acontece de interessante...
Dica: Pesquise na Internet o conceito de �Propor��o �urea" ou �Propor��o Divina�. */

int main(){

	int n;
	
	printf("Digite um valor para N: ");
	scanf( " %d", &n);
	
	int s1 = 0, s2 = 1, aux;
		
	printf("\nOs primeiros %d termos da sequencia Fibonacci:\n", n);
    for (int i = 1; i <= n; i++) {
        printf("%d ", s1);
        int temp = s1;
        s1 = s2;
        s2 = temp + s2;
    }
    printf("\n");

    float proporcao_divina = (float)s2 / s1;
    printf("\nProporcao divina (ultimo termo / penultimo termo): %.2f\n", proporcao_divina);

	return 0;
	}

