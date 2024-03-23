#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

/* 18. Crie um programa que receba um n�mero e verifique se ele � um n�mero triangular. Um n�mero � triangular quando
� resultado do produto de tr�s n�meros consecutivos.  
Exemplo: 120 = 4 x 5 x 6.*/

int main(){

	int n,prod, i;
 
	printf("Digite um valor: ");
	scanf(" %d",&n);
	
	prod = i = 1;
	
	while( prod < n){
		prod = ( i * (i + 1) * (i + 2));
		i++;
	}
		i--;
	
	if(prod == n)
    	printf("Triangular: %d = %d * %d * %d\n", n,i,i+1,i+2);
  	else
		printf("Nao e triangular\n");
 
	return 0;
	}

