/* Quest�o 3 [Fila]
Escreva um programa que simule o controle de uma pista de decolagem de avi�es em um aeroporto. 
Neste programa, o usu�rio deve ser capaz de realizar as seguintes tarefas:
a) Adicionar um avi�o na fila para decolagem;
b) Listar os avi�es aguardando na fila de decolagem;
c) Autorizar decolagem de avi�o (exclus�o do primeiro da fila);
d) Abortar a decolagem de um avi�o (alter�-lo da posi��o inicial para a posi��o final da fila);
e) Exibir as caracter�sticas do primeiro avi�o da fila;
Considere que os avi�es possuem as seguintes informa��es: NUMERO do voo, cidade de ORIGEM e 
cidade de DESTINO, quantidade de PASSAGEIROS. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defini��o da estrutura do avi�o
typedef struct Aviao {
    int numeroVoo;
    char origem[50];
    char destino[50];
    int quantidadePassageiros;
    struct Aviao *prox;
} Aviao;

int interface() {
    printf("\nOp��es:\n");
        printf("1. Adicionar avi�o na fila\n");
        printf("2. Listar avi�es na fila\n");
        printf("3. Autorizar decolagem\n");
        printf("4. Abortar decolagem\n");
        printf("5. Exibir pr�ximo avi�o na fila\n");
        printf("6. Sair\n");
    int op;
    do {
        printf("Escolha uma das Opcoes Acima: \n");
        scanf(" %d", &op);
    } while ((op < 0) || (op > 6));
    return op;
}
// Adicionar um avi�o na fila para decolagem;
void adicionarAviaoNaFila(Aviao **fila) {
    Aviao *novoAviao = (Aviao *)malloc(sizeof(Aviao));
    printf("Informe o n�mero do voo: ");
    scanf("%d", &novoAviao->numeroVoo);
    printf("Informe a cidade de origem: ");
    scanf("%s", novoAviao->origem);
    printf("Informe a cidade de destino: ");
    scanf("%s", novoAviao->destino);
    printf("Informe a quantidade de passageiros: ");
    scanf("%d", &novoAviao->quantidadePassageiros);
    novoAviao->prox = NULL;

//erifique se a fila (um ponteiro para a fila) est� vazia. Se estiver vazio, 
//significa que este � o primeiro avi�o na fila, e o ponteiro da fila (*fila) � atualizado para indica��es para o novo avi�o.
    if (*fila == NULL) { 
        *fila = novoAviao;
    } else {
        Aviao *temp = *fila; //Cria um ponteiro tempor�rio tempque aponta para o in�cio da fila.
        while (temp->prox != NULL) { // Inicia um loop que percorre a fila at� encontrar o �ltimo avi�o (o avi�o cujo pr�ximo � NULL).
            temp = temp->prox;
        }
        temp->prox = novoAviao;
    }
}
// Listar os avi�es aguardando na fila de decolagem;
void listarAvioesNaFila(Aviao *fila) {
    if (fila == NULL) {
        printf("N�o h� avi�es na fila de decolagem.\n");
        return;
    }

    printf("Avi�es aguardando na fila de decolagem:\n");
    Aviao *temp = fila;
    while (temp != NULL) {
        printf("Voo %d - Origem: %s, Destino: %s, Passageiros: %d\n",
               temp->numeroVoo, temp->origem, temp->destino, temp->quantidadePassageiros);
        temp = temp->prox;
    }
}
// Autorizar decolagem de avi�o (exclus�o do primeiro da fila);
void autorizarDecolagem(Aviao **fila) {
    if (*fila != NULL) {
        Aviao *temp = *fila;
        *fila = (*fila)->prox;
        free(temp);
        printf("Decolagem autorizada para o pr�ximo avi�o.\n");
    } else {
        printf("N�o h� avi�es na fila de decolagem.\n");
    }
}
// Abortar a decolagem de um avi�o (alter�-lo da posi��o inicial para a posi��o final da fila);
void abortarDecolagem(Aviao **fila) {
    if (*fila != NULL) {
        Aviao *temp = *fila;
        *fila = (*fila)->prox;
        temp->prox = NULL;

        if (*fila == NULL) {
            *fila = temp;
        } else {
            Aviao *last = *fila;
            while (last->prox != NULL) { //Entrar em um loop que percorre a fila at� encontrar o �ltimo avi�o (o avi�o cujo campo prox� NULL).
                last = last->prox; //Atualiza o ponteiro lastpara apontar para o pr�ximo avi�o na fila, at� que o �ltimo avi�o seja encontrado.
            }
            last->prox = temp; //Defina o campo proxdo �ltimo avi�o encontrado para apontar para o avi�o temp, movendo assim o avi�o temppara o final da fila
        }
        printf("Decolagem abortada para o avi�o.\n");
    } else {
        printf("N�o h� avi�es na fila de decolagem.\n");
    }
}

// Exibir as caracter�sticas do primeiro avi�o da fila;
void exibirPrimeiroAviao(Aviao *fila) {
    if (fila != NULL) {
        printf("Pr�ximo avi�o na fila de decolagem:\n");
        printf("Voo %d - Origem: %s, Destino: %s, Passageiros: %d\n",
               fila->numeroVoo, fila->origem, fila->destino, fila->quantidadePassageiros);
    } else {
        printf("N�o h� avi�es na fila de decolagem.\n");
    }
}

void liberarFila(Aviao *fila) {
    while (fila != NULL) {
        Aviao *temp = fila;
        fila = fila->prox;
        free(temp);
    }
}

int main() {
    Aviao *fila = NULL;

    do {
       switch (interface()) {
            case 1:
                adicionarAviaoNaFila(&fila);
                break;
            case 2:
                listarAvioesNaFila(fila);
                break;
            case 3:
                autorizarDecolagem(&fila);
                break;
            case 4:
                abortarDecolagem(&fila);
                break;
            case 5:
                exibirPrimeiroAviao(fila);
                break;
            case 6:
                return 0;
            default:
                printf("Op��o inv�lida.\n");
        }
    } while (1);

    return 0;
}
