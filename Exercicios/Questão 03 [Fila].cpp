/* Questão 3 [Fila]
Escreva um programa que simule o controle de uma pista de decolagem de aviões em um aeroporto. 
Neste programa, o usuário deve ser capaz de realizar as seguintes tarefas:
a) Adicionar um avião na fila para decolagem;
b) Listar os aviões aguardando na fila de decolagem;
c) Autorizar decolagem de avião (exclusão do primeiro da fila);
d) Abortar a decolagem de um avião (alterá-lo da posição inicial para a posição final da fila);
e) Exibir as características do primeiro avião da fila;
Considere que os aviões possuem as seguintes informações: NUMERO do voo, cidade de ORIGEM e 
cidade de DESTINO, quantidade de PASSAGEIROS. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura do avião
typedef struct Aviao {
    int numeroVoo;
    char origem[50];
    char destino[50];
    int quantidadePassageiros;
    struct Aviao *prox;
} Aviao;

int interface() {
    printf("\nOpções:\n");
        printf("1. Adicionar avião na fila\n");
        printf("2. Listar aviões na fila\n");
        printf("3. Autorizar decolagem\n");
        printf("4. Abortar decolagem\n");
        printf("5. Exibir próximo avião na fila\n");
        printf("6. Sair\n");
    int op;
    do {
        printf("Escolha uma das Opcoes Acima: \n");
        scanf(" %d", &op);
    } while ((op < 0) || (op > 6));
    return op;
}
// Adicionar um avião na fila para decolagem;
void adicionarAviaoNaFila(Aviao **fila) {
    Aviao *novoAviao = (Aviao *)malloc(sizeof(Aviao));
    printf("Informe o número do voo: ");
    scanf("%d", &novoAviao->numeroVoo);
    printf("Informe a cidade de origem: ");
    scanf("%s", novoAviao->origem);
    printf("Informe a cidade de destino: ");
    scanf("%s", novoAviao->destino);
    printf("Informe a quantidade de passageiros: ");
    scanf("%d", &novoAviao->quantidadePassageiros);
    novoAviao->prox = NULL;

//erifique se a fila (um ponteiro para a fila) está vazia. Se estiver vazio, 
//significa que este é o primeiro avião na fila, e o ponteiro da fila (*fila) é atualizado para indicações para o novo avião.
    if (*fila == NULL) { 
        *fila = novoAviao;
    } else {
        Aviao *temp = *fila; //Cria um ponteiro temporário tempque aponta para o início da fila.
        while (temp->prox != NULL) { // Inicia um loop que percorre a fila até encontrar o último avião (o avião cujo próximo é NULL).
            temp = temp->prox;
        }
        temp->prox = novoAviao;
    }
}
// Listar os aviões aguardando na fila de decolagem;
void listarAvioesNaFila(Aviao *fila) {
    if (fila == NULL) {
        printf("Não há aviões na fila de decolagem.\n");
        return;
    }

    printf("Aviões aguardando na fila de decolagem:\n");
    Aviao *temp = fila;
    while (temp != NULL) {
        printf("Voo %d - Origem: %s, Destino: %s, Passageiros: %d\n",
               temp->numeroVoo, temp->origem, temp->destino, temp->quantidadePassageiros);
        temp = temp->prox;
    }
}
// Autorizar decolagem de avião (exclusão do primeiro da fila);
void autorizarDecolagem(Aviao **fila) {
    if (*fila != NULL) {
        Aviao *temp = *fila;
        *fila = (*fila)->prox;
        free(temp);
        printf("Decolagem autorizada para o próximo avião.\n");
    } else {
        printf("Não há aviões na fila de decolagem.\n");
    }
}
// Abortar a decolagem de um avião (alterá-lo da posição inicial para a posição final da fila);
void abortarDecolagem(Aviao **fila) {
    if (*fila != NULL) {
        Aviao *temp = *fila;
        *fila = (*fila)->prox;
        temp->prox = NULL;

        if (*fila == NULL) {
            *fila = temp;
        } else {
            Aviao *last = *fila;
            while (last->prox != NULL) { //Entrar em um loop que percorre a fila até encontrar o último avião (o avião cujo campo proxé NULL).
                last = last->prox; //Atualiza o ponteiro lastpara apontar para o próximo avião na fila, até que o último avião seja encontrado.
            }
            last->prox = temp; //Defina o campo proxdo último avião encontrado para apontar para o avião temp, movendo assim o avião temppara o final da fila
        }
        printf("Decolagem abortada para o avião.\n");
    } else {
        printf("Não há aviões na fila de decolagem.\n");
    }
}

// Exibir as características do primeiro avião da fila;
void exibirPrimeiroAviao(Aviao *fila) {
    if (fila != NULL) {
        printf("Próximo avião na fila de decolagem:\n");
        printf("Voo %d - Origem: %s, Destino: %s, Passageiros: %d\n",
               fila->numeroVoo, fila->origem, fila->destino, fila->quantidadePassageiros);
    } else {
        printf("Não há aviões na fila de decolagem.\n");
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
                printf("Opção inválida.\n");
        }
    } while (1);

    return 0;
}
