/* Questão #01 [PIX]
Pix é o mais recente sistema para pagamentos e de transferência monetária implementado pelo Banco
Central do Brasil, que funciona 24 horas ininterruptamente e de forma instantânea. Desde o lançamento em 2020, 
é considerada uma das tecnologias de maior sucesso recente, e muito provavelmente você já o utilizou… Neste problema, você deverá implementar um simulacro do sistema PIX.

Considere…

NumConta => Número da Conta Corrente de uma pessoa. Por simplificação, desconsidere as outras
informações como número da agência, código do banco, etc… Pode ser auto incrementado.
NomeTitular => Nome do titular da Conta Corrente.
LimiteCredito => Valor máximo que a Conta Corrente pode ficar em saldo negativo.
SaldoAtual => Saldo atual disponível na Conta Corrente. Pode-se utilizar até o valor do LimiteCredito como
saldo negativo.
TipoChave => Tipo da chave cadastrada, sendo assim respeitado:
Valor 1 => indica chave de “CPF”
Valor 2 => indica chave de “Número Telefone”
Valor 3 => indica “Chave Aleatória”
Chave => Armazena o valor da chave para o tipo escolhido (CPF, Telefone ou Chave Aleatória)
NumConta => O número da Conta Corrente que corresponde àquela chave

Opções de Interação
1) Cadastrar Conta Bancária
2) Consultar Conta Bancária
2.1) Cadastrar Chave Pix
2.2) Realizar Transferência Pix
2.3) Voltar Menu
Operações e Restrições
a) Toda operação de cadastro deve ser realizada individualmente.
b) O programa deve garantir que a informação NumConta, na estrutura ContaBancaria, seja exclusiva.
c) Ao acessar a opção 2 (Consultar Conta Bancária), o sistema deve solicitar apenas o valor de
NumConta, e após isso, apresentar tela com todas as informações da conta (nome do titular, limite de
crédito e saldo atual), bem como as opções do sub-menu.
d) Ao se “Cadastrar nova Chave Pix”, deve-se garantir que não há duplicidade para os valores de
TipoChave e Chave informados… P. Ex… Se já existe: TipoChave == 1 e Chave == 8 não se pode
admitir outra chave com essas mesmas informações, porém, ainda poderá existir uma chave
TipoChave == 2 e Chave == 8.
e) Uma mesma conta bancária pode ter inúmeras chaves Pix cadastradas.
f) Deve-se criar uma função específica para que o próprio sistema gere uma chave aleatória, caso o
TipoChave escolhido seja “Chave Aleatória”. Essa chave deverá ter necessariamente 4 dígitos e não
poderá ser repetida.
g) Ao “Realizar Transferência Pix” deve ser solicitado ao usuário: o Tipo de Chave, o Valor da Chave e o
Valor Monetário a ser transferido. Caso: (i) exista saldo disponível, e (ii) o sistema encontre a Conta
Corrente de destino correspondente à chave Pix, então a transferência deve ser realizada atualizando
os respectivos saldos nas contas origem e destino

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONTAS 100
#define MAX_CHAVES 100

typedef struct {
    int numConta;
    char nomeTitular[50];
    float limiteCredito;
    float saldoAtual;
} ContaBancaria;

typedef struct {
    int tipoChave;
    int chave;
    int numConta;
} ChavePix;

ContaBancaria contas[MAX_CONTAS];
ChavePix chaves[MAX_CHAVES];
int numContas = 0;
int numChaves = 0;

void cadastrarConta() {
    if (numContas >= MAX_CONTAS) {
        printf("Limite de contas atingido.\n");
        return;
    }

    ContaBancaria novaConta;

  printf("\n");  
  printf("Numero da Conta: ");
    scanf(" %d", &novaConta.numConta);

    // Verificar se o Numero da conta já existe
    for (int i = 0; i < numContas; i++) {
        if (contas[i].numConta == novaConta.numConta) {
            printf("Numero da conta já cadastrado.\n");
            return;
        }
    }

    printf("Nome do Titular: ");
    scanf(" %[^\n]s", novaConta.nomeTitular);

    printf("Limite de Crédito: R$ ");
    scanf(" %f", &novaConta.limiteCredito);

    printf("Saldo Atual: R$ ");
    scanf(" %f", &novaConta.saldoAtual);

    contas[numContas] = novaConta;
    numContas++;

    printf("Conta cadastrada com sucesso!\n");
}


void gerarChaveAleatoria(int *chave) {
    srand(time(NULL));  // Inicializa a semente do gerador de Numeros aleatórios
    *chave = rand() % 10000;  // Gera um Numero aleatório entre 0 e 9999 (4 dígitos)
}

void cadastrarChavePix() {
    if (numChaves >= MAX_CHAVES) {
        printf("Limite de chaves PIX atingido.\n");
        return;
    }

    ChavePix novaChave;

    printf("\nCadastrar nova Chave Pix\n");
    printf("Tipo de Chave (1 - CPF, 2 - Numero de Telefone, 3 - Chave Aleatória): ");
    scanf(" %d", &novaChave.tipoChave);

    if (novaChave.tipoChave == 1 || novaChave.tipoChave == 2) {
        printf("Chave: ");
        scanf(" %d", &novaChave.chave);
    } else if (novaChave.tipoChave == 3) {
        gerarChaveAleatoria(&novaChave.chave);
    } else {
        printf("Tipo de Chave inválido.\n");
        return;
    }

    printf("Numero da Conta Corrente: ");
    scanf(" %d", &novaChave.numConta);

    // Verificar duplicidade de chaves
    for (int i = 0; i < numChaves; i++) {
        if (chaves[i].tipoChave == novaChave.tipoChave && chaves[i].chave == novaChave.chave) {
            printf("Essa chave já está cadastrada.\n");
            return;
        }
    }

    chaves[numChaves] = novaChave;
    numChaves++;

    printf("Chave Pix cadastrada com sucesso!\n\n");
    printf("Tipo de Chave: %d\n", novaChave.tipoChave);
    printf("Chave: %d\n", novaChave.chave);
    printf("Conta associada: %d\n", novaChave.numConta);
}

void realizarTransferencia() {
    int tipoChave, valorChave;
    float valorTransferencia;

    printf("Tipo de Chave (1 - CPF, 2 - Numero de Telefone, 3 - Chave Aleatória): ");
    scanf(" %d", &tipoChave);

    printf("Informe a chave Pix: ");
    scanf(" %d", &valorChave);

    printf("Valor da Transferencia: ");
    scanf(" %f", &valorTransferencia);

    // Verificar se a chave existe
    int contaDestino = -1;
    for (int i = 0; i < numChaves; i++) {
        if (chaves[i].tipoChave == tipoChave && chaves[i].chave == valorChave) {
            contaDestino = chaves[i].numConta;
            break;
        }
    }

    if (contaDestino == -1) {
        printf("Chave não encontrada.\n");
        return;
    }

    // Verificar se há saldo suficiente na conta origem
    int contaOrigem;
    printf("Numero da conta que deseja descontar: ");
    scanf(" %d", &contaOrigem);

    float saldoOrigem = 0.0;
    for (int i = 0; i < numContas; i++) {
        if (contas[i].numConta == contaOrigem) {
            saldoOrigem = contas[i].saldoAtual;
            break;
        }
    }

    if (saldoOrigem < valorTransferencia) {
        printf("Saldo insuficiente.\n");
        return;
    }

    // Realizar a Transferencia
    for (int i = 0; i < numContas; i++) {
        if (contas[i].numConta == contaOrigem) {
            contas[i].saldoAtual -= valorTransferencia;
        } else if (contas[i].numConta == contaDestino) {
            contas[i].saldoAtual += valorTransferencia;
        }
    }

    printf("Transferencia realizada com sucesso.\n");
}

void consultarConta() {
    int numConta;
    printf("Digite o Numero da conta Bancaria: ");
    scanf(" %d", &numConta);

    int indiceConta = -1;
    for (int i = 0; i < numContas; i++) {
        if (contas[i].numConta == numConta) {
            indiceConta = i;
            break;
        }
    }

    if (indiceConta != -1) {
        printf("\nNome do titular: %s\n", contas[indiceConta].nomeTitular);
            printf("Limite de crédito: R$ %.2f\n", contas[indiceConta].limiteCredito);
            printf("Saldo atual: R$ %.2f\n", contas[indiceConta].saldoAtual);
      
      int opcao;
        do {
            printf("\nOpcoes de Interação:\n");
            printf("1) Cadastrar Chave Pix\n");
            printf("2) Realizar Transferencia Pix\n");
            printf("3) Voltar ao Menu Principal\n");
            printf("Escolha uma opção: ");
            scanf("%d", &opcao);

            switch (opcao) {
                case 1:
                    cadastrarChavePix();
                    break;
                case 2:
                    realizarTransferencia();
                    break;
                case 3:
                    printf("Voltando ao Menu Principal...\n");
                    break;
                default:
                    printf("Opção invalida. Tente novamente.\n");
            }
        } while (opcao != 3);  // Continuar o loop até o usuário escolher voltar ao menu principal
    } else {
        printf("Conta Bancaria não encontrada.\n");
    }
}


int main() {
    int opcao;

    do {
        printf("\nOpcoes de Interação:\n");
        printf("1) Cadastrar Conta Bancaria\n");
        printf("2) Consultar Conta Bancaria\n");
        printf("3) Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarConta();
                break;
           case 2:
                consultarConta();
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção invalida. Tente novamente.\n");
        }
    } while (opcao != 3);

    return 0;
}
