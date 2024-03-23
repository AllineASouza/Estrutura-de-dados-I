#include <stdio.h>
#include <string.h>

struct Contato {
    char nome[50];
    char email[100];
    char telefone[15];
    char grupo[20];
};

int validaEmail(const char email[]) {
    int at_count = 0;
    int dot_count = 0;
    for (int i = 0; email[i] != '\0'; i++) {
        if (email[i] == '@') {
            at_count++;
        } else if (email[i] == '.') {
            dot_count++;
        } else if (email[i] == ' ') {
            return 0;
        }
    }
    return (at_count == 1 && dot_count >= 1);
}

void exibirGrupos(struct Contato contatos[], int numContatos) {
    printf("\nGrupos de Afinidade:\n");
    for (int i = 0; i < numContatos; i++) {
        printf("%s\n", contatos[i].grupo);
    }
}

void cadastrarContato(struct Contato contatos[], int *numContatos) {
    struct Contato novoContato;
    printf("\nNome: ");
    scanf("%s", novoContato.nome);

    do {
        printf("E-mail: ");
        scanf("%s", novoContato.email);
    } while (!validaEmail(novoContato.email));

    printf("Telefone: ");
    scanf("%s", novoContato.telefone);

    printf("Grupo de Afinidade: ");
    scanf("%s", novoContato.grupo);

    contatos[*numContatos] = novoContato;
    (*numContatos)++;
}

void exibirContatosPorGrupo(struct Contato contatos[], int numContatos, const char grupo[]) {
    printf("\nContatos do Grupo '%s':\n", grupo);
    for (int i = 0; i < numContatos; i++) {
        if (strcmp(contatos[i].grupo, grupo) == 0) {
            printf("Nome: %s\n", contatos[i].nome);
            printf("E-mail: %s\n", contatos[i].email);
            printf("Telefone: %s\n\n", contatos[i].telefone);
        }
    }
}

void buscarContatoPorEmail(struct Contato contatos[], int numContatos, const char email[]) {
    for (int i = 0; i < numContatos; i++) {
        if (strcmp(contatos[i].email, email) == 0) {
            printf("\nDados do Contato:\n");
            printf("Nome: %s\n", contatos[i].nome);
            printf("E-mail: %s\n", contatos[i].email);
            printf("Telefone: %s\n", contatos[i].telefone);
            printf("Grupo de Afinidade: %s\n", contatos[i].grupo);
            return;
        }
    }
    printf("\nContato não encontrado.\n");
}

int main() {
    struct Contato contatos[100];
    int numContatos = 0;
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Cadastrar Contato\n");
        printf("2. Exibir Grupos de Afinidade\n");
        printf("3. Exibir Contatos de um Grupo\n");
        printf("4. Buscar Contato por E-mail\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarContato(contatos, &numContatos);
                break;
            case 2:
                exibirGrupos(contatos, numContatos);
                break;
            case 3: {
                char grupo[20];
                printf("Digite o nome do Grupo de Afinidade: ");
                scanf("%s", grupo);
                exibirContatosPorGrupo(contatos, numContatos, grupo);
                break;
            }
            case 4: {
                char email[100];
                printf("Digite o e-mail do contato: ");
                scanf("%s", email);
                buscarContatoPorEmail(contatos, numContatos, email);
                break;
            }
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("opcao invalida. Tente novamente.\n");
                break;
        }
    } while (opcao != 5);

    return 0;
}

