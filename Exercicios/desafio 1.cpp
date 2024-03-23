#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ALUNOS 50
#define MAX_DISCIPLINAS 100

typedef struct{
	char nome[100], alunos[MAX_ALUNOS][100];
	int periodo;
	int ch;
	int numAlunos;
}Disciplina;

int main(){
	int i,j, aux=0;
	char resp;
	Disciplina disciplinas[100];
	
	printf("Cadastrando Disciplinas");
	i=0;
	do{
		printf("\nNome: ");
		scanf(" %[^\n]s", disciplinas[i].nome);
		printf("\nPeriodo: ");
		scanf(" %d", &disciplinas[i].periodo);
		printf("\nCarga horaria: ");
		scanf(" %d", &disciplinas[i].ch);
		printf("\nAlunos: ");
		for(j=0;j<MAX_ALUNOS;j++){
			printf("Nome do aluno %d(digite exit para sair)\n", j+1);
			scanf(" %[^\n]s", disciplinas[i].alunos[j]);
			if(strcmp(disciplinas[i].alunos[j],"exit")==0)
				break;
			disciplinas[j].numAlunos++;
		}	
		
		printf("Deseja cadastrar outra disciplina?");
		scanf(" %c",&resp);
		if(resp=='n' || resp=='N')
			break;
		
		i++;
	}while(i<MAX_DISCIPLINAS);
	
	printf("Imprimindo Disciplinas\n");
	for(aux=0;aux<=i;aux++){
		printf("Nome: %s", disciplinas[aux].nome);
		printf("\nPeriodo: %d", disciplinas[aux].periodo);
		printf("\nCarga horaria: %d", disciplinas[aux].ch);
		printf("\nAlunos: \n");
		j=0;
		while(j<disciplinas[aux].numAlunos){
			printf("%s\n", disciplinas[aux].alunos[j]);
			j++;
		}
	}
}
