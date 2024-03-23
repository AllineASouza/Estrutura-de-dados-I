#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

/* 3. Leia um número inteiro X. O programa deve gerar um número aleatório entre 0 e
X. Após isto, o programa deve dizer se o número sorteado é primo ou não.*/
 
int main(){
srand(time(NULL));

int x;
	
	printf("Digite um numero inteiro: ");
 	scanf(" %d", &x);
 	
	int m = rand() % (x + 1) ;
	printf("Numero aleatorio gerado: %d\n", m);
	
	int primo = 1; 
	
	if (m <= 1) {
		primo = 0; 
		} else {
			for (int i = 2; i < m; i++) {
				if (m % i == 0) {
					primo = 0; 
			break;
				}
			}	
		}
	
	if (primo) {
		printf("%d e um numero primo.\n", m);
		} else {
			printf("%d nao e um numero primo.\n", m);
	}
	
	return 0; 
}


