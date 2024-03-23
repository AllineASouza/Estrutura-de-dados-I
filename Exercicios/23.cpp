#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

/* 2. Programe uma calculadora IMC. Leia as informações e informe ao
usuário se ele está abaixo do peso, com peso normal, acima do peso ou obeso;*/

int main() {
    float peso, altura, imc;

    // Solicita ao usuário o peso em kg
    printf("Digite seu peso em kg: ");
    scanf("%f", &peso);

    // Solicita ao usuário a altura em metros
    printf("Digite sua altura em metros: ");
    scanf("%f", &altura);

    // Calcula o IMC
    imc = peso / (altura * altura);

    // Exibe o IMC
    printf("Seu IMC e: %.2f\n", imc);
    
    // Determina a categoria do IMC
    if (imc < 18.5) 
        printf("Você está abaixo do peso.\n");
    else if (imc >= 18.5 && imc < 24.9) 
        printf("Peso normal\n.\n");
    else if (imc >= 25 && imc < 29.9) 
        printf("Sobrepeso\n.\n");
    else if (imc >= 30 && imc < 34.9)
        printf("Obesidade grau 1\n");
    else if (imc >= 35 && imc < 39.9)
        printf("Obesidade grau 2\n");
    else
        printf("Obesidade grau 3\n");

    return 0;
}
