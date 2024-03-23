/* Questão 09 [Árvore Binária] 
Uma árvore binária (ou árvore de busca binária, ABB) é uma estrutura de dados onde todos os nós 
(structs) possuem um apontador para o vizinho à esqueda (sub-árvore esquerda) e um apontador para 
um vizinho à direita (sub-árvore direita). 
A organização da árvore binária é feita de modo a otimizar a busca de informações na estrutura, sendo 
assim estruturada... O valor chave da sub-árvore esquerda possui valor inferior ao do nó raiz e o valor 
chave da sub-árvore direita possui um valor superior ao nó raiz (esta é a forma padrão, podendo as subárvores serem invertidas, dependendo da aplicação).
O objetivo desta árvore portanto, é estruturar os dados de forma flexível, permitindo busca binária. */


#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dado;
    struct Nodo* esquerda;
    struct Nodo* direita;
} Nodo;

Nodo* novo_nodo(int dado) {
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    if (nodo == NULL) {
        printf("Erro ao alocar memória para o nó.\n");
        exit(EXIT_FAILURE);
    }
    nodo->dado = dado;
    nodo->esquerda = NULL;
    nodo->direita = NULL;
    return nodo;
}

void inserir(Nodo** raiz, int dado) {
    if (*raiz == NULL) {
        *raiz = novo_nodo(dado);
        return;
    }
    if (dado < (*raiz)->dado) {
        inserir(&(*raiz)->esquerda, dado);
    } else if (dado > (*raiz)->dado) {
        inserir(&(*raiz)->direita, dado);
    }
}

Nodo* buscar(Nodo* raiz, int dado, int* saltos) {
    if (raiz == NULL) {
        return NULL;
    }

    (*saltos)++;
    
    if (dado == raiz->dado) {
        return raiz;
    } else if (dado < raiz->dado) {
        return buscar(raiz->esquerda, dado, saltos);
    } else {
        return buscar(raiz->direita, dado, saltos);
    }
}

void liberar_arvore(Nodo* raiz) {
    if (raiz != NULL) {
        liberar_arvore(raiz->esquerda);
        liberar_arvore(raiz->direita);
        free(raiz);
    }
}

int main() {
    Nodo* raiz = NULL;
    int num_nos;

    printf("Quantos nós você deseja inserir na árvore? ");
    scanf("%d", &num_nos);

    for (int i = 0; i < num_nos; i++) {
        int dado;
        printf("Digite o valor do nó %d: ", i + 1);
        scanf("%d", &dado);
        inserir(&raiz, dado);
    }

    int busca_valor;
    printf("Digite o valor que deseja buscar: ");
    scanf("%d", &busca_valor);

    int saltos = 0;
    Nodo* encontrado = buscar(raiz, busca_valor, &saltos);
    
    if (encontrado != NULL) {
        printf("Valor encontrado na árvore! Número de saltos necessários: %d\n", saltos);
    } else {
        printf("Valor não encontrado na árvore.\n");
    }

    // Liberando a memória alocada para a árvore
    liberar_arvore(raiz);

    return 0;
}
