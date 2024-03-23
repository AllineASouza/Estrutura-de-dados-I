#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

/* 14. Sabendo que o valor de pi pode ser calculado através da série Gregory-Leibniz:
p = (4/1) - (4/3) + (4/5) - (4/7) + (4/9) - (4/11) + (4/13) - (4/15) …
Faça um algoritmo para calcular e imprimir o valor de pi, com 15 casas decimais, obtido até o 999.999.999º termo da
série. (Resposta correta: 3.141592654588051) */

int main(){
	
        double pi = 0.0, aux1 = 1;
        
        for(int i = 1; i <= 999999999; i++){
            if(i % 2 != 0)
            	pi += 4 / aux1;
            else
	            pi -= 4 / aux1;
	            aux1 += 2;
        }
		
		printf("\n\n%.15f\n\n", pi);
		
	return 0;
}

