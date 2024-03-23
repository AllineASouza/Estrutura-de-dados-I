#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

/* 9. Fa�a um programa que declare duas vari�veis do tipo char, fa�a a leitura, validando a entrada para que seja lido
apenas s�mbolos num�ricos (entre �0� e �9�). Ap�s isso, converta e imprima o valor da multiplica��o dos n�meros.*/


int main() {
    char a, b;

    printf("Digite dois simbolos numericos (entre '0' e '9'):\n");
    
    while (1) {
        scanf(" %c %c", &a, &b);

        if ((a >= '0' && a <= '9') && (b >= '0' && b <= '9')) {
            printf("%c * %c = %d\n", a, b, (a - '0') * (b - '0'));
            break; // Saia do loop se a entrada for v�lida
        } else {
            printf("Entrada invalida. Por favor, insira apenas simbolos numericos entre '0' e '9'.\n");
        }
    }

    return 0;
}

