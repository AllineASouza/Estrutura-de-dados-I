/* Fa�a a implementa��o de um programa utilizando uma estrutura do tipo �Lista Duplamente Encadeada�. 
Nesta abordagem, cada n�/registro cont�m o endere�o para o n�/registro seguinte e tamb�m para o 
n�/registro anterior.
a) Fa�a uma fun��o de cadastro, para inclus�o no in�cio da lista;
b) Fa�a uma fun��o de cadastro, para inclus�o ao final da lista;
c) Fa�a uma fun��o para exclus�o do primeiro elemento da lista;
d) Fa�a uma fun��o para exclus�o do �ltimo elemento da lista;
e) Fa�a uma fun��o para impress�o de toda a lista, a partir do primeiro elemento;
f) Fa�a uma fun��o para impress�o de toda a lista, a partir do �ltimo elemento;
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
    
    printf("Lista a partir do �ltimo elemento: ");
    imprimirListaFim(cabeca);

    removerPrimeiro(&cabeca);
    removerUltimo(&cabeca);
    
    printf("Lista ap�s exclus�es: ");
    imprimirListaInicio(cabeca);

    return 0;
}
