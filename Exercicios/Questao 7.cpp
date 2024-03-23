/* 4. Faça um programa que leia o nome completo de uma pessoa. O programa deve imprimir
o nome com todas as iniciais no formato maiúsculo, e demais letras no formato minúsculo. */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {

    char nome[100];
    int i;

    printf("Digite seu nome completo: ");
    scanf("%[^\n]", nome);

    strlwr(nome);

    for (i = 0; i < strlen(nome) + 1; i++) {
        if (i == 0 || nome[i - 1] == ' ')
            nome[i] = toupper(nome[i]);
        else
            nome[i] = nome[i];
    }
	printf("\n%s", nome);

    return 0;
}
