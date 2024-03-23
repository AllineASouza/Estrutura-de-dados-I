/* Problema #13 [Questão de Prova]
O Google quer te contratar, e solicitou que você programe uma ferramenta para administração de
contatos do Gmail. O sistema deverá permitir o cadastro de até 100 itens, contendo as informações:
nome do contato, e-mail, telefone e grupo de afinidade (p.e. Família, Trabalho, Amigo, etc...). O seu
programa deverá cumprir os seguintes requisitos:
- Realizar o cadastro de um contato por vez, através de um procedimento/função própria para este
fim.
- Fazer a validação do endereço de e-mail através de uma função validaEmail. Para um e-mail ser
válido, deve possuir um único símbolo “@”, pelo menos um símbolo ponto (.) após o símbolo
“@” e não possuir espaços em branco.
- O cadastro deve aceitar somente endereços de e-mails válidos.
- Antes de o usuário cadastrar o grupo de afinidade para um novo contato, o programa deve exibir
todos os grupos de afinidade já cadastrados em contatos anteriores (Dica: Crie um procedimento
exclusivamente para isso). Desta forma, o usuário poderá ver os grupos que já foram criados
antes de escolher o grupo do novo contato.
- Desenvolva um relatório (em procedimento próprio) que imprima na tela todos os contatos de
um determinado grupo de afinidade, informado pelo usuário.
- Desenvolva um procedimento que localize na base de dados um determinado e-mail (não se
esqueça de validar o endereço). Imprima na tela todos os dados do contato, ou informe se o
contato não existe.*/

#include <stdio.h>
#include <string.h>

#define MAX_CONTATOS 100
#define MAX_NOME 50
#define MAX_EMAIL 100
#define MAX_TELEFONE 20
#define MAX_GRUPO 20

typedef struct {
    char nome[MAX_NOME];
    char email[MAX_EMAIL];
    char telefone[MAX_TELEFONE];
    char grupo[MAX_GRUPO];
} Contato;

Contato contatos[MAX_CONTATOS];
char gruposAfinidade[MAX_CONTATOS][MAX_GRUPO];
int numContatos = 0;
int numGrupos = 0;

int validaEmail(const char *email) {
    int qtdArroba = 0;
    int qtdPonto = 0;

    for (int i = 0; email[i] != '\0'; i++) {
        if (email[i] == ' ') {
            return 0; // Email não pode conter espaços em branco
        } else if (email[i] == '@') {
            qtdArroba++;
        } else if (email[i] == '.' && qtdArroba == 1) {
            qtdPonto++;
        }
    }

    return (qtdArroba == 1 && qtdPonto >= 1);
}

void exibirGruposAfinidade() {
    printf("\nGrupos de Afinidade:\n");
    for (int i = 0; i < numGrupos; i++) {
        printf("- %s\n", gruposAfinidade[i]);
    }
}

void cadastrarContato() {
    if (numContatos < MAX_CONTATOS) {
        Contato novoContato;

        printf("\nNome do contato: ");
        scanf(" %[^\n]", novoContato.nome);

        do {
            printf("E-mail do contato: ");
            scanf(" %[^\n]", novoContato.email);

            if (!validaEmail(novoContato.email)) {
                printf("E-mail invalido. Tente novamente.\n");
            }
        } while (!validaEmail(novoContato.email));

        printf("Telefone do contato: ");
        scanf(" %[^\n]", novoContato.telefone);

        printf("Grupo de afinidade: ");
        scanf(" %[^\n]", novoContato.grupo);

        int grupoExistente = 0;
        for (int i = 0; i < numGrupos; i++) {
            if (strcmp(gruposAfinidade[i], novoContato.grupo) == 0) {
                grupoExistente = 1;
                break;
            }
        }

        if (!grupoExistente) {
            strcpy(gruposAfinidade[numGrupos], novoContato.grupo);
            numGrupos++;
        }

        contatos[numContatos++] = novoContato;

        printf("Contato cadastrado com sucesso!\n");
    } else {
        printf("Limite de contatos atingido.\n");
    }
}

void imprimirContatosPorGrupo(const char *grupo) {
    printf("\nContatos do grupo %s:\n", grupo);
    for (int i = 0; i < numContatos; i++) {
        if (strcmp(contatos[i].grupo, grupo) == 0) {
            printf("Nome: %s\n", contatos[i].nome);
            printf("E-mail: %s\n", contatos[i].email);
            printf("Telefone: %s\n", contatos[i].telefone);
            printf("\n");
        }
    }
}

void localizarContatoPorEmail(const char *email) {
    for (int i = 0; i < numContatos; i++) {
        if (strcmp(contatos[i].email, email) == 0) {
            printf("\nContato encontrado:\n");
            printf("Nome: %s\n", contatos[i].nome);
            printf("E-mail: %s\n", contatos[i].email);
            printf("Telefone: %s\n", contatos[i].telefone);
            printf("Grupo: %s\n", contatos[i].grupo);
            return;
        }
    }

    printf("Contato com o e-mail %s não encontrado.\n", email);
}

int main() {
    int opcao;

    do {
        printf("==== Administracao de Contatos Gmail ====\n");
        printf("1. Cadastrar Contato\n");
        printf("2. Exibir Grupos de Afinidade\n");
        printf("3. Imprimir Contatos por Grupo\n");
        printf("4. Localizar Contato por E-mail\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                exibirGruposAfinidade();
                cadastrarContato();
                break;
            case 2:
                exibirGruposAfinidade();
                break;
            case 3:
                printf("Digite o nome do grupo: ");
                char grupo[MAX_GRUPO];
                scanf(" %[^\n]", grupo);
                imprimirContatosPorGrupo(grupo);
                break;
            case 4:
                printf("Digite o e-mail do contato: ");
                char emailBusca[MAX_EMAIL];
                scanf(" %[^\n]", emailBusca);
                localizarContatoPorEmail(emailBusca);
                break;
            case 5:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("opcao invalida. Escolha novamente.\n");
        }

        printf("\n");
    } while (opcao != 5);

    return 0;
}

