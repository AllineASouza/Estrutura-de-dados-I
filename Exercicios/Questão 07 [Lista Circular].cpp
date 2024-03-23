/* Fa�a a implementa��o de um programa utilizando uma estrutura de Lista Encadeada Circular. Nesta
metodologia, o �ltimo n� da lista sempre dever� apontar para o primeiro n� (registro) da lista. Portanto,
para realizar opera��es de Inclus�o e Consulta, basta oferecer como par�metro o ponteiro do Final da
Lista.
a) Fa�a uma fun��o para cadastro na Lista Circular.
b) Fa�a uma fun��o para impress�o da Listagem Geral;
c) A lista circular trata a estrutura de lista encadeada como pilha, fila ou ambas? Por qu�? */

#include <stdio.h>
#include <stdlib.h>

// Defini��o da estrutura do n�
struct Node {
    int dado;
    struct Node* proximo;
};

// Fun��o para cadastrar um novo n� na lista
void cadastrar(struct Node** ultimo, int valor) {
    struct Node* novo_no = (struct Node*)malloc(sizeof(struct Node));
    novo_no->dado = valor;

    if (*ultimo == NULL) {
        // Se a lista estiver vazia, o novo n� ser� o primeiro e o �ltimo
        *ultimo = novo_no;
        novo_no->proximo = novo_no;  // O �ltimo n� aponta para si mesmo
    } else {
        novo_no->proximo = (*ultimo)->proximo;  // O pr�ximo do novo n� aponta para o primeiro n�
        (*ultimo)->proximo = novo_no;           // O pr�ximo do �ltimo n� aponta para o novo n�
        *ultimo = novo_no;                     // O novo n� se torna o �ltimo n�
    }
}

// Fun��o para imprimir a listagem geral
void imprimir(struct Node* ultimo) {
    if (ultimo == NULL) {
        printf("A lista est� vazia.\n");
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
        printf("Escolha uma op��o: ");
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
                printf("Op��o inv�lida.\n");
        }
    } while (escolha != 0);

    return 0;
}

