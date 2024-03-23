/* Crie um programa que cadastre dinamicamente (através de lista encadeada) e ordenadamente, os 
produtos de uma loja de departamentos (código de barras, descrição do produto, quantidade em 
estoque, valor de venda).
a) Faça uma função para imprimir a relação de todos os produtos.
b) Faça uma função para exclusão de um determinado item, através do código de barras.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Produto {
    int codigo;
    char descricao[50];
    int quantidade;
    float valor;
    struct Produto* proximo;
} Produto;

Produto* inserirProduto(Produto* lista, int codigo, const char* descricao, int quantidade, float valor) {
    Produto* novoProduto = (Produto*)malloc(sizeof(Produto));
    if (novoProduto == NULL) {
        printf("Erro ao alocar memória para o novo produto.\n");
        exit(1);
    }

    novoProduto->codigo = codigo;
    strcpy(novoProduto->descricao, descricao);
    novoProduto->quantidade = quantidade;
    novoProduto->valor = valor;
    novoProduto->proximo = lista;

    return novoProduto;
}

void imprimirProdutos(Produto* lista) {
    printf("Código\tDescrição\tQuantidade\tValor\n");
    printf("---------------------------------------------------\n");
    while (lista != NULL) {
        printf("%d\t%s\t%d\t\t%.2f\n", lista->codigo, lista->descricao, lista->quantidade, lista->valor);
        lista = lista->proximo;
    }
    printf("---------------------------------------------------\n");
}

Produto* excluirProduto(Produto* lista, int codigo) {
    Produto* atual = lista;
    Produto* anterior = NULL;

    while (atual != NULL && atual->codigo != codigo) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Produto com código %d não encontrado.\n", codigo);
        return lista;
    }

    if (anterior == NULL) {
        lista = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual);
    printf("Produto com código %d excluído com sucesso.\n", codigo);
    return lista;
}

int main() {
    Produto* listaProdutos = NULL;

    listaProdutos = inserirProduto(listaProdutos, 1021, "Camiseta", 50, 29.99);
    listaProdutos = inserirProduto(listaProdutos, 2015, "Calça Jeans", 30, 59.99);
    listaProdutos = inserirProduto(listaProdutos, 3050, "Tênis Esportivo", 20, 99.99);

    printf("Lista de Produtos:\n");
    imprimirProdutos(listaProdutos);

    listaProdutos = excluirProduto(listaProdutos, 2015);

    printf("\nLista de Produtos após exclusão:\n");
    imprimirProdutos(listaProdutos);

    return 0;
}
