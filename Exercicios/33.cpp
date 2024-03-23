/* Uma reta em um plano bidimensional pode ser representada a partir de dois pontos: ponto A, composto pelas coordenadas Xa e Ya, e ponto B, representado pelas coordenadas Xb e Yb. 
Fa�a um programa que modele structs do tipo Ponto e tipo Reta2D. Fa�a com que o usu�rio cadastre duas retas, utilizando a defini��o de Reta2D. O programa deve 
calcular informar se as duas retas atingidas pelo usu�rio s�o PARALELAS, PERPENDICULARES ou NENHUMA das duas. Obs.: Utilize o conceito de �coeficiente angular de reta� para determinar estas condi��es.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>

// Fa�a um programa que modele structs do tipo Ponto e tipo Reta2D.
typedef struct {
    int x;
    int y;
} Ponto;

typedef struct {
    Ponto pontoA;
    Ponto pontoB;
} Reta2D;

int main(){
setlocale(LC_ALL, "Portuguese");
 
// Fa�a com que o usu�rio cadastre duas retas, utilizando a defini��o de Reta2D.*/
	Reta2D reta1, reta2;
	float a, b;

	// Cadastro da primeira reta
	printf("Reta 1:\n");
	printf("Ponto A: (Xa Ya): ");
	scanf(" %d %d", &reta1.pontoA.x, &reta1.pontoA.y);
	printf("Ponto B: (Xb Yb): ");
   	scanf(" %d %d", &reta1.pontoB.x, &reta1.pontoB.y);
	
	// Cadastro da segunda reta
	printf("Reta 2:\n");
	printf("Ponto A: (Xa Ya): ");
    scanf(" %d %d", &reta2.pontoA.x, &reta2.pontoA.y);
	printf("Ponto B: (Xb Yb): ");
	scanf(" %d %d", &reta2.pontoB.x, &reta2.pontoB.y);
	
	
	// C�lculo dos coeficientes angulares
    a = (float)(reta1.pontoB.y - reta1.pontoA.y) / (reta1.pontoB.x - reta1.pontoA.x);
    b = (float)(reta2.pontoB.y - reta2.pontoA.y) / (reta2.pontoB.x - reta2.pontoA.x);

	// Verifica��o das rela��es entre as retas
    if (a == b) 
        printf("As retas s�o paralelas.\n");
    	else if (a * b == -1) 
        	printf("As retas s�o perpendiculares.\n");
    else 
        printf("NENHUMA das duas.\n");
    
	
	
return 0;
}

