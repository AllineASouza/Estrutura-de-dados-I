#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

/* 3. Utilizando a estrutura condicional Switch-Case, implemente uma calculadora que recebe um valor inteiro A, um sinal
de operação e outro valor inteiro B. Imprima o resultado da operação correspondente. As operações permitidas são:
		+ Adição 
		% Resto de Divisão
		- Subtração 
		^ Exponenciação
		* Multiplicação
		/ Divisão 																					*/
		
int main(){

 int a, b;
    char operador;

    printf("\t\tCalculadora!\n");
    printf("\nEscolha uma das operacoes abaixo:\n");
    printf("\n+ Adicao");
    printf("\n- Subtracao");
    printf("\n* Multiplicacao");
    printf("\n/ Divisao");
    printf("\n%% Resto de Divisao");
    printf("\n^ Exponenciacao\n");

    printf("\nDigite o primeiro numero: ");
    scanf("%d", &a);

    printf("Digite o operador: ");
    scanf(" %c", &operador); // Note o espaço antes do %c, para consumir o newline deixado pela leitura anterior

    printf("Digite o segundo numero: ");
    scanf("%d", &b);

    switch (operador) {
        case '+':
            printf("\n%d + %d = %d\n", a, b, a + b);
            break;
        case '-':
            printf("\n%d - %d = %d\n", a, b, a - b);
            break;
        case '*':
            printf("\n%d * %d = %d\n", a, b, a * b);
            break;
        case '/':
            if (b != 0)
                printf("\n%d / %d = %.2f\n", a, b, (float) a / b);
            else
                printf("\nErro: divisao por zero!\n");
            break;
        case '%':
            printf("\n%d %% %d = %d\n", a, b, a % b);
            break;
        case '^':
            printf("\n%d ^ %d = %.0f\n", a, b, pow(a, b));
            break;
        default:
            printf("\nOperador invalido!\n");
            break;
    }
	
	return 0;
}
