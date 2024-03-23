/* Crie um programa que armazene dinamicamente informações de veículos e suas multas.
Veículo = Modelo, Placa, Ano, (e Apontador para Multas). 
Multas = Data, Código da Infração, Valor Multa, (e Apontador para Próxima Multa);
a) Crie uma função para realizar o cadastro de veículos;
b) Crie uma função para realizar o cadastro de multas de um determinado carro através da placa;
c) Crie uma função que leia do usuário uma placa, e imprima os dados referentes a esse carro, 
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

// Estrutura para representar um veículo
typedef struct Veiculo {
    char modelo[50];
    char placa[10];
    int ano;
    Multa *multas;
    struct Veiculo *prox;
} Veiculo;

// Função para cadastrar um veículo
void cadastrarVeiculo(Veiculo **listaVeiculos) {
    Veiculo *novoVeiculo = (Veiculo *)malloc(sizeof(Veiculo));
    if (novoVeiculo == NULL) {
        printf("Erro ao alocar memória para o veículo.\n");
        return;
    }

    printf("Digite o modelo do veículo: ");
    scanf("%s", novoVeiculo->modelo);
    printf("Digite a placa do veículo: ");
    scanf("%s", novoVeiculo->placa);
    printf("Digite o ano do veículo: ");
    scanf("%d", &novoVeiculo->ano);

    novoVeiculo->multas = NULL;
    novoVeiculo->prox = *listaVeiculos;
    *listaVeiculos = novoVeiculo;

    printf("Veículo cadastrado com sucesso.\n");
}

// Função para cadastrar uma multa para um veículo com uma determinada placa
void cadastrarMulta(Veiculo *listaVeiculos, const char *placa) {
    Veiculo *atual = listaVeiculos;
    while (atual != NULL) {
        if (strcmp(atual->placa, placa) == 0) {
            Multa *novaMulta = (Multa *)malloc(sizeof(Multa));
            if (novaMulta == NULL) {
                printf("Erro ao alocar memória para a multa.\n");
                return;
            }

            printf("Digite a data da multa: ");
            scanf("%s", novaMulta->data);
            printf("Digite o código da infração: ");
            scanf("%d", &novaMulta->codigo);
            printf("Digite o valor da multa: ");
            scanf("%f", &novaMulta->valor);

            novaMulta->proxima = atual->multas;
            atual->multas = novaMulta;

            printf("Multa cadastrada com sucesso para o veículo de placa %s.\n", placa);
            return;
        }
        atual = atual->prox;
    }
    printf("Veículo de placa %s não encontrado.\n", placa);
}

// Função para imprimir os dados de um veículo e suas multas
void imprimirDados(Veiculo *veiculo) {
    printf("Modelo: %s\n", veiculo->modelo);
    printf("Placa: %s\n", veiculo->placa);
    printf("Ano: %d\n", veiculo->ano);

    Multa *multaAtual = veiculo->multas;
    float totalMultas = 0;
    while (multaAtual != NULL) {
        printf("Multa - Data: %s, Código: %d, Valor: %.2f\n", multaAtual->data, multaAtual->codigo, multaAtual->valor);
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
        printf("1. Cadastrar veículo\n");
        printf("2. Cadastrar multa\n");
        printf("3. Imprimir dados de um veículo\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarVeiculo(&listaVeiculos);
                break;
            case 2: {
                char placa[10];
                printf("Digite a placa do veículo: ");
                scanf("%s", placa);
                cadastrarMulta(listaVeiculos, placa);
                break;
            }
            case 3: {
                char placa[10];
                printf("Digite a placa do veículo: ");
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
                    printf("Veículo de placa %s não encontrado.\n", placa);
                }
                break;
            }
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 4);

    // Liberar a memória alocada
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

