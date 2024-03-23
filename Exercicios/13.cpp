#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

/* 13. Fa�a um programa que gere N n�meros de matr�cula no formato ABCD-V, onde V � um d�gito verificador, no qual:
			V = | A � B + C � D |
se V >= 10, ent�o V = d1+d2 (a soma dos dois d�gitos). */

int main() {
    int N;

    // Solicita ao usu�rio que insira a quantidade de n�meros de matr�cula a serem gerados
    printf("Digite a quantidade de numeros de matricula a serem gerados: ");
    scanf(" %d", &N);

    // Gera N n�meros de matr�cula
    for (int i = 0; i < N; i++) {
        // Gera os d�gitos A, B, C e D aleatoriamente (de 0 a 9)
        int A = rand() % 10;
        int B = rand() % 10;
        int C = rand() % 10;
        int D = rand() % 10;

        // Calcula o d�gito verificador V
        int V = abs(A - B + C - D);

        // Se V for maior ou igual a 10, calculamos a soma dos seus d�gitos
        if (V >= 10) {
            int d1 = V / 10;
            int d2 = V % 10;
            V = d1 + d2;
        }

        // Imprime o n�mero de matr�cula no formato ABCD-V
        printf("%d%d%d%d-%d\n", A, B, C, D, V);
    }

    return 0;
}


