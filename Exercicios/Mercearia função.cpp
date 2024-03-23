#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//MERCEARIA

typedef struct{
	int codigo;
	char descricao[100];
	int qtdeEstoque;
	float valorUnitario;
}Produto;

int interface(){
	printf("1 - Cadastrar Novo Produto\n");
	printf("2 - Vender Produto\n");
	printf("3 - Relatório de Produtos\n");
	printf("0 - ENCERRAR PROGRAMA\n");
	int opt;
	do{
		scanf(" %d", &opt);
	}while((opt <0 ) || (opt >3));
			
	return opt;
}


Produto setProduto(int cont){
	Produto novo;
	novo.codigo = cont;
	printf("Codigo de Barras: %d\n",novo.codigo);
	printf("Informe o Nome do Produto: ");
	scanf(" %[^\n]s", novo.descricao);
	printf("Informe o Valor do Produto: ");
	scanf(" %f", &novo.valorUnitario);
	printf("Informe a Qtde em Estoque: ");
	scanf(" %d", &novo.qtdeEstoque);
	//(...)
	return novo;
}

void getProdutos(Produto vet[],int cont){
	for(int i=0; i<cont; i++)
		printf("Codigo: %02d\nNome: %s\nValor: %.2f\nQtde: %02d\n\n",
			vet[i].codigo,
			vet[i].descricao,
			vet[i].valorUnitario,
			vet[i].qtdeEstoque);
}

void setVenda(Produto vet[],int cont){
	printf("Codigo de Barras: ");
	int c;
	scanf(" %d",&c);
	int p = -1;
	for(int i=0; i<cont; i++)
		if(c == vet[i].codigo){
			p = i;
			break;
		}
	if(p<0){
		printf("Codigo Inexistente no Estoque\n");
		return;
	}
	
	printf("Codigo: %02d\nNome: %s\nValor: %.2f\nQtde: %02d\n\n",
		vet[p].codigo,
		vet[p].descricao,
		vet[p].valorUnitario,
		vet[p].qtdeEstoque);
	
	printf("Deseja Quantos Itens?");
	int qtde;
	scanf(" %d", &qtde);
	
	if((qtde>0)&& (qtde<=vet[p].qtdeEstoque)){
		printf("VENDA REALIZADA COM SUCESSO!\n");
		vet[p].qtdeEstoque -= qtde;
	} else
		printf("Quantidade Informada Invalida!\n");
}

int main(){
	Produto vetorProdutos[100];
	int contProduto = 0;

	do{
		switch(interface()){
			case 1: //chamar funcao para cadastrar produto 
					vetorProdutos[contProduto] = setProduto(contProduto);
					contProduto++;
					break;
			case 2: //chamar funcao para vender produto
					setVenda(vetorProdutos,contProduto);
					break;
			case 3: //chamar funcao para relatorio de produtos
					getProdutos(vetorProdutos,contProduto);
					break;
			case 0: return 0;
		}
	}while(1);
}
