#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

/* 9. Faça um programa que declare duas variáveis do tipo char, faça a leitura, validando a entrada para que seja lido
apenas símbolos numéricos (entre ‘0’ e ‘9’). Após isso, converta e imprima o valor da multiplicação dos números.*/


int main() {
    char a, b;

    printf("Digite dois simbolos numericos (entre '0' e '9'):\n");
    
    while (1) {
        scanf(" %c %c", &a, &b);

        if ((a >= '0' && a <= '9') && (b >= '0' && b <= '9')) {
            printf("%c * %c = %d\n", a, b, (a - '0') * (b - '0'));
            break; // Saia do loop se a entrada for válida
        } else {
            printf("Entrada invalida. Por favor, insira apenas simbolos numericos entre '0' e '9'.\n");
        }
    }

    return 0;
}

