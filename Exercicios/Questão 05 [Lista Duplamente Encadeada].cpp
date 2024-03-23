/* Faça a implementação de um programa utilizando uma estrutura do tipo “Lista Duplamente Encadeada”. 
Nesta abordagem, cada nó/registro contém o endereço para o nó/registro seguinte e também para o 
nó/registro anterior.
a) Faça uma função de cadastro, para inclusão no início da lista;
b) Faça uma função de cadastro, para inclusão ao final da lista;
c) Faça uma função para exclusão do primeiro elemento da lista;
d) Faça uma função para exclusão do último elemento da lista;
e) Faça uma função para impressão de toda a lista, a partir do primeiro elemento;
f) Faça uma função para impressão de toda a lista, a partir do último elemento;
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* proximo;
    struct Node* anterior;
} Node;

Node* criarNo(int data) {
    Node* novoNo = (Node*)malloc(sizeof(Node));
    novoNo->data = data;
    novoNo->proximo = NULL;
    novoNo->anterior = NULL;
    return novoNo;
}

void inserirNoInicio(Node** cabeca, int data) {
    Node* novoNo = criarNo(data);
    if (*cabeca == NULL) {
        *cabeca = novoNo;
    } else {
        novoNo->proximo = *cabeca;
        (*cabeca)->anterior = novoNo;
        *cabeca = novoNo;
    }
}

void inserirNoFim(Node** cabeca, int data) {
    Node* novoNo = criarNo(data);
    if (*cabeca == NULL) {
        *cabeca = novoNo;
    } else {
        Node* atual = *cabeca;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novoNo;
        novoNo->anterior = atual;
    }
}

void removerPrimeiro(Node** cabeca) {
    if (*cabeca != NULL) {
        Node* temp = *cabeca;
        *cabeca = (*cabeca)->proximo;
        if (*cabeca != NULL) {
            (*cabeca)->anterior = NULL;
        }
        free(temp);
    }
}

void removerUltimo(Node** cabeca) {
    if (*cabeca != NULL) {
        Node* atual = *cabeca;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        if (atual->anterior != NULL) {
            atual->anterior->proximo = NULL;
        } else {
            *cabeca = NULL;
        }
        free(atual);
    }
}

void imprimirListaInicio(Node* cabeca) {
    Node* atual = cabeca;
    while (atual != NULL) {
        printf("%d ", atual->data);
        atual = atual->proximo;
    }
    printf("\n");
}

void imprimirListaFim(Node* cabeca) {
    Node* atual = cabeca;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }
    while (atual != NULL) {
        printf("%d ", atual->data);
        atual = atual->anterior;
    }
    printf("\n");
}

int main() {
    Node* cabeca = NULL;

    inserirNoInicio(&cabeca, 3);
    inserirNoInicio(&cabeca, 2);
    inserirNoInicio(&cabeca, 1);
    
    inserirNoFim(&cabeca, 4);
    inserirNoFim(&cabeca, 5);
    
    printf("Lista a partir do primeiro elemento: ");
    imprimirListaInicio(cabeca);
    
    printf("Lista a partir do último elemento: ");
    imprimirListaFim(cabeca);

    removerPrimeiro(&cabeca);
    removerUltimo(&cabeca);
    
    printf("Lista após exclusões: ");
    imprimirListaInicio(cabeca);

    return 0;
}
