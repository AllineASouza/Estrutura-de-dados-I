/* Quest�o 09 [�rvore Bin�ria] 
Uma �rvore bin�ria (ou �rvore de busca bin�ria, ABB) � uma estrutura de dados onde todos os n�s 
(structs) possuem um apontador para o vizinho � esqueda (sub-�rvore esquerda) e um apontador para 
um vizinho � direita (sub-�rvore direita). 
A organiza��o da �rvore bin�ria � feita de modo a otimizar a busca de informa��es na estrutura, sendo 
assim estruturada... O valor chave da sub-�rvore esquerda possui valor inferior ao do n� raiz e o valor 
chave da sub-�rvore direita possui um valor superior ao n� raiz (esta � a forma padr�o, podendo as sub�rvores serem invertidas, dependendo da aplica��o).
O objetivo desta �rvore portanto, � estruturar os dados de forma flex�vel, permitindo busca bin�ria. */


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
        printf("Erro ao alocar mem�ria para o n�.\n");
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

    printf("Quantos n�s voc� deseja inserir na �rvore? ");
    scanf("%d", &num_nos);

    for (int i = 0; i < num_nos; i++) {
        int dado;
        printf("Digite o valor do n� %d: ", i + 1);
        scanf("%d", &dado);
        inserir(&raiz, dado);
    }

    int busca_valor;
    printf("Digite o valor que deseja buscar: ");
    scanf("%d", &busca_valor);

    int saltos = 0;
    Nodo* encontrado = buscar(raiz, busca_valor, &saltos);
    
    if (encontrado != NULL) {
        printf("Valor encontrado na �rvore! N�mero de saltos necess�rios: %d\n", saltos);
    } else {
        printf("Valor n�o encontrado na �rvore.\n");
    }

    // Liberando a mem�ria alocada para a �rvore
    liberar_arvore(raiz);

    return 0;
}
