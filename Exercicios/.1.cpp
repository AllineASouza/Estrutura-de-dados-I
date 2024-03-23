/* EX011 - Desenvolva um aplicativo "Livro de Receitas". Crie uma estrutura RECEITA com as seguintes informações:
 * NOME da receita, TEMPO de preparo (em minutos), DIFICULDADE (F - M - D) e INGREDIENTES. Cada
 * ingrediente possui as seguintes informações: DESCRIÇÃO do ingrediente, QUANTIDADE. Uma receita
 * suporta até 30 ingredientes.Seu aplicativo deve oferecer as seguintes funcionalidades:
 * ● Cadastrar Receita (Uma por vez).
 * ● Consultar uma Receita (O usuário deve informar o nome ou apenas parte do nome de uma receita buscada).
 * ● Consultar todas as receitas que possuem um determinado ingrediente (ou parte do nome de umingrediente) informado pelo usuário.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

typedef struct{
	char name[MAX];
	int temp;
	char dif;
	char ingrediente[30][MAX];
	int numIngredientes;
	int qntIngrediente[30];
}Receita;

void linha(int tam){
	printf("\n");
	for(int i = 0; i < tam; i++)
		printf("-=");
	printf("\n");
}
	
int interface(){
	int op;
	linha(20);
	printf(" 1 - CADASTRAR RECEITA\n 2 - PROCURAR RECEITA\n 0 - ENCERRAR");
	linha(20);
	scanf(" %d", &op);
	return op;
}
void cadastroReceita(Receita receita[], int *cont){
	linha(25);
	printf("\t\t\tCADASTRO RECEITA");
	linha(25);
	
	*cont = *cont + 1;
	printf("Receita: %d\n", *cont);
	printf("Nome da receita:" );
	scanf(" %[^\n]s", receita[*cont].name);
	printf("Tempo de preparo(MIN):");
	scanf(" %d", &receita[*cont].temp);
	printf("Nível de Dificuldade(F - M - D): ");
	scanf(" %c", &receita[*cont].dif);
	linha(20);
	printf("\tIngredientes");
	linha(20);
	char continuar;
	int i = 0;
	do{
		printf("Ingrediente %d:", i+1);
		scanf(" %[^\n]s", receita[*cont].ingrediente[i]);
		printf("Quantidade: ");
		scanf(" %d", &receita[*cont].qntIngrediente[i]);
		printf("Adicionar mais ingredientes(S | N): ");
		scanf(" %c", &continuar);
		i++;
	}while((continuar == 's' || continuar == 'S') && i < 30);
	receita[*cont].numIngredientes = i;
	printf("FIM DO CADASTRO\n");
	system("clear");
}


void consultaReceita(Receita receita[], int i){
	printf("Número receita: %d\nNome: %s\nTempo de preparo: %d\nNível de Dificuldade: %c\n", i, receita[i].name, receita[i].temp, receita[i].dif);
	for(int j = 0; j < receita[i].numIngredientes; j++)
		printf("Ingrediente %d: %s\nQuantidade: %d\n", j, receita[i].ingrediente[j], receita[i].qntIngrediente[j]);
}

void consultaIngrediente(Receita receita[], char procura_ingrediente[]){
	for(int i = 0; i < MAX;i++){
		for(int j = 0; j < receita[i].numIngredientes;j++){
				if(strstr(receita[i].ingrediente[j], procura_ingrediente)){
					consultaReceita(receita, i);
					}
		}
	}
}

int main()
{
	Receita receita[MAX];
	int cont = 0;
	int resp;
	do{
	 resp = interface();
		if(resp == 1){
		cadastroReceita(receita, &cont);
		}else if(resp == 2){
			int op;
			linha(20);
			printf(" 1 - NOME\n 2 - INGREDIENTE ");
			linha(20);
			printf("Digite o modo de busca: ");
			scanf(" %d", &op);
				if(op == 1){
					
					char procura[MAX];
					printf("Digite o nome da receita que deseja encontrar: ");
					scanf(" %[^\n]s", procura);
						for(int i = 0; i < 100; i++){
							if(strstr(receita[i].name, procura) != 0){
								consultaReceita(receita, i);
							}
						}
				}
				if(op == 2){
					char procura[MAX];
					printf("Digite o nome do ingredinete que deseja procurar: ");
					scanf(" %[^\n]s", procura);
					consultaIngrediente(receita, procura);
				}
		}
	}while(resp != 0);
	
	return 0;
}
