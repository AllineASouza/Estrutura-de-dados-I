/* Crie um programa que armazene dinamicamente informa��es de ve�culos e suas multas.
Ve�culo = Modelo, Placa, Ano, (e Apontador para Multas). 
Multas = Data, C�digo da Infra��o, Valor Multa, (e Apontador para Pr�xima Multa);
a) Crie uma fun��o para realizar o cadastro de ve�culos;
b) Crie uma fun��o para realizar o cadastro de multas de um determinado carro atrav�s da placa;
c) Crie uma fun��o que leia do usu�rio uma placa, e imprima os dados referentes a esse carro, 
suas multas e o valor total de multas */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para representar uma multa
typedef struct Multa {
    char data[20];
    int codigo;
    float valor;
    struct Multa *proxima;
} Multa;

// Estrutura para representar um ve�culo
typedef struct Veiculo {
    char modelo[50];
    char placa[10];
    int ano;
    Multa *multas;
    struct Veiculo *prox;
} Veiculo;

// Fun��o para cadastrar um ve�culo
void cadastrarVeiculo(Veiculo **listaVeiculos) {
    Veiculo *novoVeiculo = (Veiculo *)malloc(sizeof(Veiculo));
    if (novoVeiculo == NULL) {
        printf("Erro ao alocar mem�ria para o ve�culo.\n");
        return;
    }

    printf("Digite o modelo do ve�culo: ");
    scanf("%s", novoVeiculo->modelo);
    printf("Digite a placa do ve�culo: ");
    scanf("%s", novoVeiculo->placa);
    printf("Digite o ano do ve�culo: ");
    scanf("%d", &novoVeiculo->ano);

    novoVeiculo->multas = NULL;
    novoVeiculo->prox = *listaVeiculos;
    *listaVeiculos = novoVeiculo;

    printf("Ve�culo cadastrado com sucesso.\n");
}

// Fun��o para cadastrar uma multa para um ve�culo com uma determinada placa
void cadastrarMulta(Veiculo *listaVeiculos, const char *placa) {
    Veiculo *atual = listaVeiculos;
    while (atual != NULL) {
        if (strcmp(atual->placa, placa) == 0) {
            Multa *novaMulta = (Multa *)malloc(sizeof(Multa));
            if (novaMulta == NULL) {
                printf("Erro ao alocar mem�ria para a multa.\n");
                return;
            }

            printf("Digite a data da multa: ");
            scanf("%s", novaMulta->data);
            printf("Digite o c�digo da infra��o: ");
            scanf("%d", &novaMulta->codigo);
            printf("Digite o valor da multa: ");
            scanf("%f", &novaMulta->valor);

            novaMulta->proxima = atual->multas;
            atual->multas = novaMulta;

            printf("Multa cadastrada com sucesso para o ve�culo de placa %s.\n", placa);
            return;
        }
        atual = atual->prox;
    }
    printf("Ve�culo de placa %s n�o encontrado.\n", placa);
}

// Fun��o para imprimir os dados de um ve�culo e suas multas
void imprimirDados(Veiculo *veiculo) {
    printf("Modelo: %s\n", veiculo->modelo);
    printf("Placa: %s\n", veiculo->placa);
    printf("Ano: %d\n", veiculo->ano);

    Multa *multaAtual = veiculo->multas;
    float totalMultas = 0;
    while (multaAtual != NULL) {
        printf("Multa - Data: %s, C�digo: %d, Valor: %.2f\n", multaAtual->data, multaAtual->codigo, multaAtual->valor);
        totalMultas += multaAtual->valor;
        multaAtual = multaAtual->proxima;
    }
    printf("Total de multas: %.2f\n", totalMultas);
}

int main() {
    Veiculo *listaVeiculos = NULL;

    int opcao;
    do {
        printf("\nMenu:\n");
        printf("1. Cadastrar ve�culo\n");
        printf("2. Cadastrar multa\n");
        printf("3. Imprimir dados de um ve�culo\n");
        printf("4. Sair\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarVeiculo(&listaVeiculos);
                break;
            case 2: {
                char placa[10];
                printf("Digite a placa do ve�culo: ");
                scanf("%s", placa);
                cadastrarMulta(listaVeiculos, placa);
                break;
            }
            case 3: {
                char placa[10];
                printf("Digite a placa do ve�culo: ");
                scanf("%s", placa);
                Veiculo *atual = listaVeiculos;
                while (atual != NULL) {
                    if (strcmp(atual->placa, placa) == 0) {
                        imprimirDados(atual);
                        break;
                    }
                    atual = atual->prox;
                }
                if (atual == NULL) {
                    printf("Ve�culo de placa %s n�o encontrado.\n", placa);
                }
                break;
            }
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Op��o inv�lida.\n");
        }
    } while (opcao != 4);

    // Liberar a mem�ria alocada
    while (listaVeiculos != NULL) {
        Veiculo *prox = listaVeiculos->prox;
        Multa *multaAtual = listaVeiculos->multas;
        while (multaAtual != NULL) {
            Multa *proximaMulta = multaAtual->proxima;
            free(multaAtual);
            multaAtual = proximaMulta;
        }
        free(listaVeiculos);
        listaVeiculos = prox;
    }

    return 0;
}

