/* Crie um programa que cadastre dinamicamente (atrav�s de lista encadeada) e ordenadamente, os 
produtos de uma loja de departamentos (c�digo de barras, descri��o do produto, quantidade em 
estoque, valor de venda).
a) Fa�a uma fun��o para imprimir a rela��o de todos os produtos.
b) Fa�a uma fun��o para exclus�o de um determinado item, atrav�s do c�digo de barras.
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
        printf("Erro ao alocar mem�ria para o novo produto.\n");
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
    printf("C�digo\tDescri��o\tQuantidade\tValor\n");
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
        printf("Produto com c�digo %d n�o encontrado.\n", codigo);
        return lista;
    }

    if (anterior == NULL) {
        lista = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual);
    printf("Produto com c�digo %d exclu�do com sucesso.\n", codigo);
    return lista;
}

int main() {
    Produto* listaProdutos = NULL;

    listaProdutos = inserirProduto(listaProdutos, 1021, "Camiseta", 50, 29.99);
    listaProdutos = inserirProduto(listaProdutos, 2015, "Cal�a Jeans", 30, 59.99);
    listaProdutos = inserirProduto(listaProdutos, 3050, "T�nis Esportivo", 20, 99.99);

    printf("Lista de Produtos:\n");
    imprimirProdutos(listaProdutos);

    listaProdutos = excluirProduto(listaProdutos, 2015);

    printf("\nLista de Produtos ap�s exclus�o:\n");
    imprimirProdutos(listaProdutos);

    return 0;
}
