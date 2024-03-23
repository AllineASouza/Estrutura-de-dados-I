/*Faça um programa que gera aleatoriamente uma aposta da lotofácil 
(15 números não repetitivos no intervalo entre 01 e 25).*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	
	srand(time(NULL));
	
	int v[15], sorteado[25], cont = 0;
	
	for(int i = 0; i < 25; i++)
		sorteado[i] = 0;
	
	while(cont < 15){
		int x = 1 + rand() %25;
		if(sorteado[x] == 0){
			v[cont] = x;
			sorteado[x] = 1;
			cont++;
		}
	}
	for(int i = 0; i < 15; i++)
		printf(" %d\n", v[i]);
	
	return 0;
}
