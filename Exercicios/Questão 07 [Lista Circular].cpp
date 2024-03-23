/* Faça a implementação de um programa utilizando uma estrutura de Lista Encadeada Circular. Nesta
metodologia, o último nó da lista sempre deverá apontar para o primeiro nó (registro) da lista. Portanto,
para realizar operações de Inclusão e Consulta, basta oferecer como parâmetro o ponteiro do Final da
Lista.
a) Faça uma função para cadastro na Lista Circular.
b) Faça uma função para impressão da Listagem Geral;
c) A lista circular trata a estrutura de lista encadeada como pilha, fila ou ambas? Por quê? */

#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó
struct Node {
    int dado;
    struct Node* proximo;
};

// Função para cadastrar um novo nó na lista
void cadastrar(struct Node** ultimo, int valor) {
    struct Node* novo_no = (struct Node*)malloc(sizeof(struct Node));
    novo_no->dado = valor;

    if (*ultimo == NULL) {
        // Se a lista estiver vazia, o novo nó será o primeiro e o último
        *ultimo = novo_no;
        novo_no->proximo = novo_no;  // O último nó aponta para si mesmo
    } else {
        novo_no->proximo = (*ultimo)->proximo;  // O próximo do novo nó aponta para o primeiro nó
        (*ultimo)->proximo = novo_no;           // O próximo do último nó aponta para o novo nó
        *ultimo = novo_no;                     // O novo nó se torna o último nó
    }
}

// Função para imprimir a listagem geral
void imprimir(struct Node* ultimo) {
    if (ultimo == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    struct Node* atual = ultimo->proximo;
    do {
        printf("%d ", atual->dado);
        atual = atual->proximo;
    } while (atual != ultimo->proximo);
    printf("\n");
}

int main() {
    struct Node* ultimo = NULL;
    int escolha, valor;

    do {
        printf("1 - Cadastrar\n");
        printf("2 - Imprimir Listagem Geral\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite o valor a ser cadastrado: ");
                scanf("%d", &valor);
                cadastrar(&ultimo, valor);
                break;
            case 2:
                printf("Listagem Geral: ");
                imprimir(ultimo);
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (escolha != 0);

    return 0;
}

