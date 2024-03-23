#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

/* 16. Fa�a um programa que leia dois valores inteiros X e Y, tal que Y >= X. O programa dever� sortear N valores no
intervalo entre X e Y (inclusive). Obs.: Os n�meros sorteados no intervalo entre X e Y n�o podem ser obtidos por
tentativa e erro! */

int main() {
    int x, y;

    printf("Digite dois numeros, tal que o segundo numero seja maior:\n");
    scanf("%d %d", &x, &y);

    // Verifica se y � maior ou igual a x
    if (y < x) {
        printf("Erro: O segundo numero deve ser maior ou igual ao primeiro.\n");
        return 1; // Encerra o programa com c�digo de erro
    }

    printf("Numeros sorteados no intervalo entre %d e %d:\n", x, y);
    for (int i = x; i <= y; i++) {
        int numero_sorteado = rand() % (y - x + 1) + x; // Gera um n�mero aleat�rio no intervalo [x, y]
        printf("%d ", numero_sorteado);
    }
    printf("\n");

    return 0;
}

