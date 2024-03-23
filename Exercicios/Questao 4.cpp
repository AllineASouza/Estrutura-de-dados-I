/*Sorteie números aleatórios para preencher uma tabela NxN (o valor
N definido pelo usuário). Imprima os nºs em formato de tabela.*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	
	int n;
	printf("Informe o tamanho da matriz: ");
	scanf(" %d", &n);
	int m[n][n];
	
	for (int l = 0; l < n ; l++)
		for (int c = 0; c < n; c++)
			m[l][c] = rand()%100;
	
	for(int l = 0; l < n; l++){
		printf("\n");
		for(int c = 0; c < n; c++)
			printf("%d\t",m[l][c]);
	}
	
	return 0;
}


