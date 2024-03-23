/* Problema #11
Desenvolva um aplicativo "Livro de Receitas". Crie uma estrutura RECEITA com as seguintes informações:
NOME da receita, TEMPO de preparo (em minutos), DIFICULDADE (F - M - D) e INGREDIENTES. Cada
ingrediente possui as seguintes informações: DESCRIÇÃO do ingrediente, QUANTIDADE. Uma receita
suporta até 30 ingredientes.
Seu aplicativo deve oferecer as seguintes funcionalidades:
- Cadastrar Receita (Uma por vez).
- Consultar uma Receita (O usuário deve informar o nome ou apenas parte do nome de uma
receita buscada).
- Consultar todas as receitas que possuem um determinado ingrediente (ou parte do nome de um
ingrediente) informado pelo usuário.*/

#include <stdio.h>
#include <string.h>

#define MAX_RECEITAS 100
#define MAX_INGREDIENTES 30
#define MAX_DESCRICAO 100
#define MAX_NOME 50

typedef struct {
    char descricao[MAX_DESCRICAO];
    char quantidade[MAX_DESCRICAO];
} Ingrediente;

typedef struct {
    char nome[MAX_NOME];
    int tempoPreparo;
    char dificuldade;
    Ingrediente ingredientes[MAX_INGREDIENTES];
    int numIngredientes;
} Receita;

Receita receitas[MAX_RECEITAS];
int numReceitas = 0;

void cadastrarReceita() {
    if (numReceitas < MAX_RECEITAS) {
        Receita novaReceita;

        printf("\nNome da receita: ");
        scanf(" %[^\n]", novaReceita.nome);

        printf("Tempo de preparo (minutos): ");
        scanf(" %d", &novaReceita.tempoPreparo);

        printf("Dificuldade (F - Facil, M - Media, D - Dificil): ");
        scanf(" %c", &novaReceita.dificuldade);

        printf("Numero de ingredientes: ");
        scanf("%d", &novaReceita.numIngredientes);

        for (int i = 0; i < novaReceita.numIngredientes; i++) {
            printf("\nIngrediente %d:\n", i + 1);
            printf("Descricao: ");
            scanf(" %[^\n]", novaReceita.ingredientes[i].descricao);
            printf("Quantidade: ");
            scanf(" %[^\n]", novaReceita.ingredientes[i].quantidade);
        }

        receitas[numReceitas++] = novaReceita;
        printf("\nReceita cadastrada com sucesso!\n");
    } else {
        printf("Limite de receitas atingido.\n");
    }
}

void consultarReceitaPorNome() {
    char nomeBusca[MAX_NOME];
    printf("\nDigite o nome da receita ou parte dele: ");
    scanf(" %[^\n]", nomeBusca);

    printf("Resultados da busca:\n");

    for (int i = 0; i < numReceitas; i++) {
        if (strcmp(receitas[i].nome, nomeBusca) == 0) {
            printf("\nNome: %s\n", receitas[i].nome);
            printf("Tempo de preparo: %d minutos\n", receitas[i].tempoPreparo);
            printf("Dificuldade: %c\n", receitas[i].dificuldade);

            printf("Ingredientes:\n");
            for (int j = 0; j < receitas[i].numIngredientes; j++) {
                printf("- %s: %s\n", receitas[i].ingredientes[j].descricao, receitas[i].ingredientes[j].quantidade);
            }

            printf("\n");
        }
    }
}

void consultarReceitasPorIngrediente() {
    char ingredienteBusca[MAX_DESCRICAO];
    printf("\nDigite o nome do ingrediente ou parte dele: ");
    scanf(" %[^\n]", ingredienteBusca);

    printf("Resultados da busca:\n");

    for (int i = 0; i < numReceitas; i++) {
        for (int j = 0; j < receitas[i].numIngredientes; j++) {
            if (strcmp(receitas[i].ingredientes[j].descricao, ingredienteBusca) == 0) {
                printf("\nNome: %s\n", receitas[i].nome);
                printf("Tempo de preparo: %d minutos\n", receitas[i].tempoPreparo);
                printf("Dificuldade: %c\n", receitas[i].dificuldade);

                printf("\nIngredientes:\n");
                for (int k = 0; k < receitas[i].numIngredientes; k++) {
                    printf("- %s: %s\n", receitas[i].ingredientes[k].descricao, receitas[i].ingredientes[k].quantidade);
                }

                printf("\n");
                break;
            }
        }
    }
}

int main() {
    int opcao;

    do {
        printf("==== Livro de Receitas ====\n");
        printf("1. Cadastrar Receita\n");
        printf("2. Consultar Receita por Nome\n");
        printf("3. Consultar Receitas por Ingrediente\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf(" %d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarReceita();
                break;
            case 2:
                consultarReceitaPorNome();
                break;
            case 3:
                consultarReceitasPorIngrediente();
                break;
            case 4:
                printf("Encerrando o aplicativo.\n");
                break;
            default:
                printf("Opção inválida. Escolha novamente.\n");
        }

        printf("\n");
    } while (opcao != 4);

    return 0;
}

