/* Quest�o #01 [PIX]
Pix � o mais recente sistema para pagamentos e de transfer�ncia monet�ria implementado pelo Banco
Central do Brasil, que funciona 24 horas ininterruptamente e de forma instant�nea. Desde o lan�amento em 2020, 
� considerada uma das tecnologias de maior sucesso recente, e muito provavelmente voc� j� o utilizou� Neste problema, voc� dever� implementar um simulacro do sistema PIX.

Considere�

NumConta => N�mero da Conta Corrente de uma pessoa. Por simplifica��o, desconsidere as outras
informa��es como n�mero da ag�ncia, c�digo do banco, etc� Pode ser auto incrementado.
NomeTitular => Nome do titular da Conta Corrente.
LimiteCredito => Valor m�ximo que a Conta Corrente pode ficar em saldo negativo.
SaldoAtual => Saldo atual dispon�vel na Conta Corrente. Pode-se utilizar at� o valor do LimiteCredito como
saldo negativo.
TipoChave => Tipo da chave cadastrada, sendo assim respeitado:
Valor 1 => indica chave de �CPF�
Valor 2 => indica chave de �N�mero Telefone�
Valor 3 => indica �Chave Aleat�ria�
Chave => Armazena o valor da chave para o tipo escolhido (CPF, Telefone ou Chave Aleat�ria)
NumConta => O n�mero da Conta Corrente que corresponde �quela chave

Op��es de Intera��o
1) Cadastrar Conta Banc�ria
2) Consultar Conta Banc�ria
2.1) Cadastrar Chave Pix
2.2) Realizar Transfer�ncia Pix
2.3) Voltar Menu
Opera��es e Restri��es
a) Toda opera��o de cadastro deve ser realizada individualmente.
b) O programa deve garantir que a informa��o NumConta, na estrutura ContaBancaria, seja exclusiva.
c) Ao acessar a op��o 2 (Consultar Conta Banc�ria), o sistema deve solicitar apenas o valor de
NumConta, e ap�s isso, apresentar tela com todas as informa��es da conta (nome do titular, limite de
cr�dito e saldo atual), bem como as op��es do sub-menu.
d) Ao se �Cadastrar nova Chave Pix�, deve-se garantir que n�o h� duplicidade para os valores de
TipoChave e Chave informados� P. Ex� Se j� existe: TipoChave == 1 e Chave == 8 n�o se pode
admitir outra chave com essas mesmas informa��es, por�m, ainda poder� existir uma chave
TipoChave == 2 e Chave == 8.
e) Uma mesma conta banc�ria pode ter in�meras chaves Pix cadastradas.
f) Deve-se criar uma fun��o espec�fica para que o pr�prio sistema gere uma chave aleat�ria, caso o
TipoChave escolhido seja �Chave Aleat�ria�. Essa chave dever� ter necessariamente 4 d�gitos e n�o
poder� ser repetida.
g) Ao �Realizar Transfer�ncia Pix� deve ser solicitado ao usu�rio: o Tipo de Chave, o Valor da Chave e o
Valor Monet�rio a ser transferido. Caso: (i) exista saldo dispon�vel, e (ii) o sistema encontre a Conta
Corrente de destino correspondente � chave Pix, ent�o a transfer�ncia deve ser realizada atualizando
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

    // Verificar se o Numero da conta j� existe
    for (int i = 0; i < numContas; i++) {
        if (contas[i].numConta == novaConta.numConta) {
            printf("Numero da conta j� cadastrado.\n");
            return;
        }
    }

    printf("Nome do Titular: ");
    scanf(" %[^\n]s", novaConta.nomeTitular);

    printf("Limite de Cr�dito: R$ ");
    scanf(" %f", &novaConta.limiteCredito);

    printf("Saldo Atual: R$ ");
    scanf(" %f", &novaConta.saldoAtual);

    contas[numContas] = novaConta;
    numContas++;

    printf("Conta cadastrada com sucesso!\n");
}


void gerarChaveAleatoria(int *chave) {
    srand(time(NULL));  // Inicializa a semente do gerador de Numeros aleat�rios
    *chave = rand() % 10000;  // Gera um Numero aleat�rio entre 0 e 9999 (4 d�gitos)
}

void cadastrarChavePix() {
    if (numChaves >= MAX_CHAVES) {
        printf("Limite de chaves PIX atingido.\n");
        return;
    }

    ChavePix novaChave;

    printf("\nCadastrar nova Chave Pix\n");
    printf("Tipo de Chave (1 - CPF, 2 - Numero de Telefone, 3 - Chave Aleat�ria): ");
    scanf(" %d", &novaChave.tipoChave);

    if (novaChave.tipoChave == 1 || novaChave.tipoChave == 2) {
        printf("Chave: ");
        scanf(" %d", &novaChave.chave);
    } else if (novaChave.tipoChave == 3) {
        gerarChaveAleatoria(&novaChave.chave);
    } else {
        printf("Tipo de Chave inv�lido.\n");
        return;
    }

    printf("Numero da Conta Corrente: ");
    scanf(" %d", &novaChave.numConta);

    // Verificar duplicidade de chaves
    for (int i = 0; i < numChaves; i++) {
        if (chaves[i].tipoChave == novaChave.tipoChave && chaves[i].chave == novaChave.chave) {
            printf("Essa chave j� est� cadastrada.\n");
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

    printf("Tipo de Chave (1 - CPF, 2 - Numero de Telefone, 3 - Chave Aleat�ria): ");
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
        printf("Chave n�o encontrada.\n");
        return;
    }

    // Verificar se h� saldo suficiente na conta origem
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
            printf("Limite de cr�dito: R$ %.2f\n", contas[indiceConta].limiteCredito);
            printf("Saldo atual: R$ %.2f\n", contas[indiceConta].saldoAtual);
      
      int opcao;
        do {
            printf("\nOpcoes de Intera��o:\n");
            printf("1) Cadastrar Chave Pix\n");
            printf("2) Realizar Transferencia Pix\n");
            printf("3) Voltar ao Menu Principal\n");
            printf("Escolha uma op��o: ");
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
                    printf("Op��o invalida. Tente novamente.\n");
            }
        } while (opcao != 3);  // Continuar o loop at� o usu�rio escolher voltar ao menu principal
    } else {
        printf("Conta Bancaria n�o encontrada.\n");
    }
}


int main() {
    int opcao;

    do {
        printf("\nOpcoes de Intera��o:\n");
        printf("1) Cadastrar Conta Bancaria\n");
        printf("2) Consultar Conta Bancaria\n");
        printf("3) Sair\n");
        printf("Escolha uma op��o: ");
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
                printf("Op��o invalida. Tente novamente.\n");
        }
    } while (opcao != 3);

    return 0;
}
