/* 3. Faça um programa que leia 3 palavras. O programa deve imprimir as três palavras 
lidas em ordem alfabética. */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main(){
	
	char nomes[3][100], aux[100];
	
	printf("Escreva 3 palavras:\n\n");
	
	for(int i=0; i<3; i++)
	scanf("%s", nomes[i]);

	for(int i=0; i<3; i++) {
	for(int j=0; j<3; j++) {
		if(strcmp(nomes[i], nomes[j]) < 0) {
		strcpy(aux, nomes[i]);
		strcpy(nomes[i], nomes[j]);
		strcpy(nomes[j], aux);
		}
	}
}
	printf("\nNomes ordenados\n\n");
	
	for(int i=0; i<3; i++)
	printf("%s\n", nomes[i]);

return 0;
}
