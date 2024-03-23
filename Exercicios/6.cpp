#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

/* 6. Sabia que a sequência Fibonacci está ligada intimamente à natureza? Os números da série são facilmente
encontrados nos seres vivos e no meio ambiente. Essa série é infinita e se inicia com os valores: 1, 1, 2, 3, 5, 8, 13,
21, 34, (...), onde o próximo valor sempre será a soma dos dois valores anteriores.
Faça um programa que leia um valor N, e imprima todos N primeiros termos da série Fibonacci.
Após isso, imprima o resultado da divisão do último termo pelo penúltimo termo.
Repita essa mesma operação para diversos valores de N diferentes, e veja o que acontece de interessante...
Dica: Pesquise na Internet o conceito de “Proporção Áurea" ou “Proporção Divina”. */

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

