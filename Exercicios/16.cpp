#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

/* 16. Faça um programa que leia dois valores inteiros X e Y, tal que Y >= X. O programa deverá sortear N valores no
intervalo entre X e Y (inclusive). Obs.: Os números sorteados no intervalo entre X e Y não podem ser obtidos por
tentativa e erro! */

int main() {
    int x, y;

    printf("Digite dois numeros, tal que o segundo numero seja maior:\n");
    scanf("%d %d", &x, &y);

    // Verifica se y é maior ou igual a x
    if (y < x) {
        printf("Erro: O segundo numero deve ser maior ou igual ao primeiro.\n");
        return 1; // Encerra o programa com código de erro
    }

    printf("Numeros sorteados no intervalo entre %d e %d:\n", x, y);
    for (int i = x; i <= y; i++) {
        int numero_sorteado = rand() % (y - x + 1) + x; // Gera um número aleatório no intervalo [x, y]
        printf("%d ", numero_sorteado);
    }
    printf("\n");

    return 0;
}

