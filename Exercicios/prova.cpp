#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_VEICULOS 100
#define MAX_VIAGENS 100
#define MAX_PASSAGEIROS 100

typedef struct {
    int codigo;
    char placa[10];
    int capacidadePassageiros;
    int emManutencao;
} Veiculo;

typedef struct {
    char cidadeOrigem[50];
    char cidadeDestino[50];
    int codigoVeiculo;
    int poltronas[100];
    float precoPassagem;
    int poltronasVendidas;
} Viagem;

Veiculo frota[MAX_VEICULOS];
int numVeiculos = 0;

Viagem viagens[MAX_VIAGENS];
int numViagens = 0;

void adicionarVeiculo() {
    if (numVeiculos < MAX_VEICULOS) {
        Veiculo novoVeiculo;
        printf("Digite o código do veículo: ");
        scanf("%d", &novoVeiculo.codigo);
        printf("Digite a placa do veículo: ");
        scanf("%s", novoVeiculo.placa);
        printf("Digite a capacidade de passageiros: ");
        scanf("%d", &novoVeiculo.capacidadePassageiros);
        printf("O veículo está em manutenção? (0 = Não, 1 = Sim): ");
        scanf("%d", &novoVeiculo.emManutencao);

        frota[numVeiculos++] = novoVeiculo;
        printf("Veículo adicionado à frota.\n");
    } else {
        printf("A frota está cheia.\n");
    }
}

void adicionarViagem() {
    if (numViagens < MAX_VIAGENS) {
        Viagem novaViagem;
        printf("Digite a cidade de origem: ");
        scanf("%s", novaViagem.cidadeOrigem);
        printf("Digite a cidade de destino: ");
        scanf("%s", novaViagem.cidadeDestino);

        int codigoVeiculo;
        printf("Digite o código do veículo para esta viagem: ");
        scanf("%d", &codigoVeiculo);

        int indiceVeiculo = -1;
        for (int i = 0; i < numVeiculos; i++) {
            if (frota[i].codigo == codigoVeiculo) {
                indiceVeiculo = i;
                break;
            }
        }

        if (indiceVeiculo != -1 && !frota[indiceVeiculo].emManutencao) {
            novaViagem.codigoVeiculo = codigoVeiculo;
            novaViagem.precoPassagem = 50.0; // Exemplo de preço da passagem

            srand(time(NULL));
            for (int i = 0; i < 100; i++) {
                novaViagem.poltronas[i] = rand() % 2; // Atribuição aleatória de 0 ou 1 (ocupada ou livre)
                if (novaViagem.poltronas[i] == 1) {
                    novaViagem.poltronasVendidas++;
                }
            }

            viagens[numViagens++] = novaViagem;
            printf("Viagem adicionada.\n");
        } else {
            printf("Código do veículo inválido ou o veículo está em manutenção.\n");
        }
    } else {
        printf("A lista de viagens está cheia.\n");
    }
}

void venderPassagem() {
    char cidadeOrigem[50];
    char cidadeDestino[50];
    
    printf("Digite a cidade de origem da viagem: ");
    scanf("%s", cidadeOrigem);
    printf("Digite a cidade de destino da viagem: ");
    scanf("%s", cidadeDestino);
    
    int indiceViagem = -1;
    for (int i = 0; i < numViagens; i++) {
        if (strcmp(viagens[i].cidadeOrigem, cidadeOrigem) == 0 && strcmp(viagens[i].cidadeDestino, cidadeDestino) == 0) {
            indiceViagem = i;
            break;
        }
    }
    
    if (indiceViagem != -1) {
        printf("Viagem encontrada!\n");
        Viagem viagem = viagens[indiceViagem];
        
        printf("Poltronas disponíveis:\n");
        for (int i = 0; i < 100; i++) {
            if (viagem.poltronas[i] == 0) {
                printf("%d ", i + 1);
            }
        }
        printf("\n");
        
        int poltronaEscolhida;
        printf("Digite o número da poltrona que deseja reservar: ");
        scanf("%d", &poltronaEscolhida);
        
        if (poltronaEscolhida >= 1 && poltronaEscolhida <= 100 && viagem.poltronas[poltronaEscolhida - 1] == 0) {
            viagem.poltronas[poltronaEscolhida - 1] = 1;
            viagem.poltronasVendidas++;
            printf("Passagem vendida com sucesso!\n");
        } else {
            printf("Poltrona inválida ou já ocupada.\n");
        }
    } else {
        printf("Viagem não encontrada.\n");
    }
}

void imprimirFrota() {
    if (numVeiculos > 0) {
        printf("\n--- Frota de Veículos ---\n");
        for (int i = 0; i < numVeiculos; i++) {
            printf("Código: %d\n", frota[i].codigo);
            printf("Placa: %s\n", frota[i].placa);
            printf("Capacidade de Passageiros: %d\n", frota[i].capacidadePassageiros);
            printf("Em Manutenção: %s\n", frota[i].emManutencao ? "Sim" : "Não");
            printf("------------------------\n");
        }
    } else {
        printf("A frota está vazia.\n");
    }
}

void imprimirViagensEArrecadacao() {
    printf("Viagens e Arrecadação:\n");
    for (int i = 0; i < numViagens; i++) {
        Viagem viagem = viagens[i];

        printf("\nViagem %d:\n", i + 1);
        printf("Cidade de Origem: %s\n", viagem.cidadeOrigem);
        printf("Cidade de Destino: %s\n", viagem.cidadeDestino);
        printf("Código do Veículo: %d\n", viagem.codigoVeiculo);
        printf("Preço da Passagem: %.2f\n", viagem.precoPassagem);
        printf("Poltronas Vendidas: %d\n", viagem.poltronasVendidas);

        float arrecadacao = viagem.precoPassagem * viagem.poltronasVendidas;
        printf("Arrecadação da Viagem: %.2f\n", arrecadacao);

        printf("Poltronas Ocupadas: ");
        for (int j = 0; j < 100; j++) {
            if (viagem.poltronas[j] == 1) {
                printf("%d ", j + 1);
            }
        }
        printf("\n");

        printf("Poltronas Livres: ");
        for (int j = 0; j < 100; j++) {
            if (viagem.poltronas[j] == 0) {
                printf("%d ", j + 1);
            }
        }
        printf("\n");
    }
}


int main() {
    int opcao;
    do {
        printf("\n1) Adicionar Veículo\n2) Adicionar Viagem\n3) Vender Passagem\n4) Imprimir Frota\n5) Imprimir Viagens e Arrecadação\n0) Sair\n");
        printf("Digite sua opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarVeiculo();
                break;
            case 2:
                adicionarViagem();
                break;
            case 3:
                venderPassagem();
                break;
            case 4:
                imprimirFrota();
                break;
            case 5:
                imprimirViagensEArrecadacao();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Por favor, escolha uma opção válida.\n");
        }
    } while (opcao != 0);

    return 0;
}

