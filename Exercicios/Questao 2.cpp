/* 2. Um apostador joga um dado para o ar N vezes. Sabendo que um
dado possui 6 faces, faça um programa que simule o experimento, e
imprima quantas vezes que cada face caiu para cima. */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

	srand(time(NULL));
	int n;
	printf("Informe a quantidade de vezes que deseja jogar o dado: ");
	scanf(" %d", &n);
	int num_sorteado[n];

	for(int i = 0; i < n; i++){
		num_sorteado[i] = 1 + rand() % 6;
			printf("%d\n", num_sorteado[i]);
		}
	int cont[6] = {0,0,0,0,0,0};
	
	for(int i = 0; i < n; i++){
		int x = num_sorteado[i];
			cont[x-1]++;
		}
	for(int i = 0; i < 6; i++)
		printf("A face %d foi sorteada %d vezes\n", i+1, cont[i]);

	return 0;
}
