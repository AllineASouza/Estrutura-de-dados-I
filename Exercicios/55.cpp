#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
/*Problema #13 [Questão de Prova]
O Google quer te contratar, e solicitou que você programe uma ferramenta para administração de contatos do Gmail. O sistema deverá permitir o cadastro de até 100 itens, contendo as informações: nome do contato, e-mail, telefone e grupo de afinidade (p.e. Família, Trabalho, Amigo, etc...). O seu
programa deverá cumprir os seguintes requisitos:
● Realizar o cadastro de um contato por vez, através de um procedimento/função própria para este fim.
● Fazer a validação do endereço de e-mail através de uma função validaEmail. Para um e-mail ser válido, deve possuir um único símbolo “@”, pelo menos um símbolo ponto (.) após o símbolo “@” e não possuir espaços em branco.
● O cadastro deve aceitar somente endereços de e-mails válidos.
● Antes de o usuário cadastrar o grupo de afinidade para um novo contato, o programa deve exibir todos os grupos de afinidade já cadastrados em contatos anteriores (Dica: Crie um procedimento exclusivamente para isso). Desta forma, o usuário poderá ver os grupos que já foram criados antes de escolher o grupo do novo contato.
● Desenvolva um relatório (em procedimento próprio) que imprima na tela todos os contatos de um determinado grupo de afinidade, informado pelo usuário.
● Desenvolva um procedimento que localize na base de dados um determinado e-mail (não se esqueça de validar o endereço). Imprima na tela todos os dados do contato, ou informe se o contato não existe.*/
#define MAX_CONTATOS 100
#define MAX_DESCRICAO 100

typedef struct{
	char nome[MAX_DESCRICAO];
	char email[MAX_DESCRICAO]; 
	char telefone[MAX_DESCRICAO];
	char gpAfinidade[MAX_DESCRICAO];
	int num_gpafinidade;
}Contato;
int interface(){
	printf("1 - Cadastrar Contato\n");
	printf("2 - Exibir Grupos De Afinidade\n");
	printf("3 - Consultar Contato por Grupo de Afinidade\n");
	printf("4 - Consultar Contato por E-mail\n");
	printf("0 - ENCERRAR PROGRAMA\n");
	int op;
	do{
		printf("Escolha uma das opcoes acima:\n");
		scanf(" %d", &op);
	}while((op < 0) || (op > 4));
	return op;
}
int validarEmail(char email[]){
	int contarroba=0, contponto=0, contespaco=0;
	if((email[0]<='A') || (email[0]>='z')){
		return 0;
	}
	for(int i=0; email[i] != '\0';i++){
		if(email[i] == '@'){//contarroba
			contarroba++;
		}
		if(email[i] == '.'){//contponto
			contponto++;
		}
		if(email[i] == ' '){//contespaco
			contespaco = 1;
			break;
		}
	}
	if((contarroba != 1) || (contponto < 1) || (contespaco == 1)){
		return 0;
	}  
	return 1;  
}
void  getgpafinidade(Contato a[], int cont){
	printf("\nGrupo De Afinidade já Cadastrado\n");
	for(int i=0;i<cont;i++){
		printf("%s - ", a[i].gpAfinidade);
	}
	printf("\n\n");
} 
Contato setcontato(Contato a[], int contContato){
	Contato nv;
	printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\t----MENU----\t\n\nNome: \n");
	scanf(" %[^\n]s", nv.nome);
	do{
		printf("E-Mail: \n");
		scanf(" %[^\n]s", nv.email);
		if(validarEmail(nv.email)){
			printf("E-mail Valido\n");
			break;
		}else{
			printf("E-mail Invalido\n");
			continue;
		}
	}while(!validarEmail(nv.email));
	printf("Telefone: \n");
	scanf(" %[^\n]s", nv.telefone);
	printf("\nEscolha Um ou Cadastre Um Novo\n");
	getgpafinidade(a, contContato);
	scanf(" %[^\n]s", nv.gpAfinidade);
	printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	return nv;
}
void getconsultar_por_gpAfinidade(Contato b[], int contcontato){
	char buscagp[MAX_DESCRICAO];
	int achou=0;
	printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\nInforme O Grupo de Afinidade\n");
	scanf(" %[^\n]s", buscagp);
	printf("\n\tContatos\t\nFiltro de Busca: %s\n", buscagp);
	for(int i=0;i<contcontato;i++){
		if(strcmp(b[i].gpAfinidade,buscagp) == 0){
			printf("Nome: %s\nE-Mail: %s\nTelefone: %s\nGrupo de Afinidade: %s\n", b[i].nome,b[i].email,b[i].telefone,b[i].gpAfinidade);
			achou=1;
		}
	}
	if(!achou){
		printf("\nNenhum Contato no Grupo Buscado\n");
	}
	printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
}
void getconsulta_por_email(Contato a[], int cont){
	char buscaremail[MAX_DESCRICAO];
	int achou=0;
	printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\nInforme o E-mail da Busca:\n");
	scanf(" %[^\n]s", buscaremail);
	printf("\n\tContatos Encontrados:\t\n");
	for(int i=0;i<cont;i++){
		if (strcmp(a[i].email, buscaremail) == 0) {
			printf("Nome: %s\nE-Mail: %s\nTelefone: %s\nGrupo de Afinidade: %s\n", a[i].nome, a[i].email, a[i].telefone, a[i].gpAfinidade);
			achou = 1;
		}
	}
	if(!achou){
		printf("\nNenhum Contato Cadastrado com o E-Mail Informado!\n");
	}
	printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
}
int main(void) {
	Contato c[MAX_CONTATOS];
	int contcontato=0;
	do{
		switch(interface()){
			case 1:
				c[contcontato] = setcontato(c,contcontato);
				contcontato++;
				break;
			case 2:
				getgpafinidade(c,contcontato);
				break;
			case 3: 
				getconsultar_por_gpAfinidade(c,contcontato);
				break;
			case 4:
				getconsulta_por_email(c,contcontato);
				break;
			case 0:
				system("clear");
				printf("\nEncerrando...\n");
				return 0;
		}
	}while(1);
  return 0;
}
