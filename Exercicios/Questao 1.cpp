/*1. Fa�a um programa que sorteie um vetor com 100 n�meros
aleat�rios entre 0 e 9. Pe�a para o usu�rio informar um n�mero X e
imprima quantas vezes o n�mero X foi sorteado anteriormente. */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	
	int cont = 0, x, v[100];
	
	printf("Digite um numero: ");
	scanf(" %d", &x);
	
	for (int i = 0; i < 100; i++){
		v[i] = rand() % 10;
		printf(" %d\n", v[i]);{
		if(v[i] == x)
		cont++;}
	}
	printf("\nO numero %d foi sorteado %d vezes.", x, cont);
	
	return 0;
}
