/* Desafio Cajuí

Faça um programa que usando funções e structs simule o funcionamento do Cajuí. 
Deve permitir o cadastro de Alunos (Código Aluno, Nome do Aluno e Nome do Curso), Disciplinas (Código Disciplina, Nome Disciplina, Carga Horária, Curso e todos os códigos dos Alunos matriculados nesta disciplina).

Restrições:
Um mesmo aluno não pode se matricular na mesma disciplina mais de uma vez.
Um mesmo aluno não pode se matricular em disciplinas que somem mais de 400 horas.
Imprimir Relatório de todas as Disciplinas de um Curso
Imprimir Relatório de todos Alunos em uma Disciplina
*/

#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 100
#define MAX_DISCIPLINAS 50

// Structs
typedef struct {
    int codigo;
    char nome[50];
    char curso[50];
} Aluno;

typedef struct {
    int codigo;
    char nome[50];
    int cargaHoraria;
    char curso[50];
    int alunosMatriculados[MAX_ALUNOS];
    int qtdAlunos;
} Disciplina;

void cadastrarAluno(Aluno alunos[], int *qtdAlunos) {
    if (*qtdAlunos < MAX_ALUNOS) {
        Aluno aluno;
        printf("Codigo do Aluno: ");
        scanf("%d", &aluno.codigo);
        printf("Nome do Aluno: ");
        scanf("%s", aluno.nome);
        printf("Nome do Curso: ");
        scanf("%s", aluno.curso);

        // Verificar se o aluno já existe
        int i;
        for (i = 0; i < *qtdAlunos; i++) {
            if (alunos[i].codigo == aluno.codigo) {
                printf("Aluno já cadastrado.\n");
                return;
            }
        }

        alunos[*qtdAlunos] = aluno;
        (*qtdAlunos)++;
        printf("Aluno cadastrado com sucesso.\n");
    } else {
        printf("Limite de alunos atingido.\n");
    }
}

void cadastrarDisciplina(Disciplina disciplinas[], int *qtdDisciplinas) {
    if (*qtdDisciplinas < MAX_DISCIPLINAS) {
        Disciplina disciplina;
        printf("Codigo da Disciplina: ");
        scanf("%d", &disciplina.codigo);
        printf("Nome da Disciplina: ");
        scanf("%s", disciplina.nome);
        printf("Carga Horária: ");
        scanf("%d", &disciplina.cargaHoraria);
        printf("Nome do Curso: ");
        scanf("%s", disciplina.curso);
        disciplina.qtdAlunos = 0;

        // Verificar se a disciplina já existe
        int i;
        for (i = 0; i < *qtdDisciplinas; i++) {
            if (disciplinas[i].codigo == disciplina.codigo) {
                printf("Disciplina já cadastrada.\n");
                return;
            }
        }

        disciplinas[*qtdDisciplinas] = disciplina;
        (*qtdDisciplinas)++;
        printf("Disciplina cadastrada com sucesso.\n");
    } else {
        printf("Limite de disciplinas atingido.\n");
    }
}

void matricularAluno(Disciplina disciplinas[], int qtdDisciplinas, Aluno alunos[], int qtdAlunos) {
    int codigoAluno, codigoDisciplina;
    printf("Codigo do Aluno: ");
    scanf("%d", &codigoAluno);
    printf("Codigo da Disciplina: ");
    scanf("%d", &codigoDisciplina);

    // Encontrar o aluno pelo Codigo
    Aluno *aluno = NULL;
    for (int i = 0; i < qtdAlunos; i++) {
        if (alunos[i].codigo == codigoAluno) {
            aluno = &alunos[i];
            break;
        }
    }

    // Encontrar a disciplina pelo Codigo
    Disciplina *disciplina = NULL;
    for (int i = 0; i < qtdDisciplinas; i++) {
        if (disciplinas[i].codigo == codigoDisciplina) {
            disciplina = &disciplinas[i];
            break;
        }
    }

    if (aluno && disciplina) {
        // Verificar se o aluno já está matriculado na disciplina
        for (int i = 0; i < disciplina->qtdAlunos; i++) {
            if (disciplina->alunosMatriculados[i] == aluno->codigo) {
                printf("Aluno já matriculado nesta disciplina.\n");
                return;
            }
        }

        // Verificar carga horária
        int cargaHorariaTotal = disciplina->cargaHoraria;
        for (int i = 0; i < disciplina->qtdAlunos; i++) {
            for (int j = 0; j < qtdDisciplinas; j++) {
                if (alunos[disciplina->alunosMatriculados[i]].codigo == codigoAluno) {
                    cargaHorariaTotal += disciplinas[j].cargaHoraria;
                }
            }
        }

        if (cargaHorariaTotal > 400) {
            printf("Aluno não pode se matricular nesta disciplina devido à carga horária.\n");
            return;
        }

        // Matricular aluno
        disciplina->alunosMatriculados[disciplina->qtdAlunos] = aluno->codigo;
        disciplina->qtdAlunos++;
        printf("Aluno matriculado com sucesso.\n");
    } else {
        printf("Aluno ou disciplina não encontrados.\n");
    }
}

void relatorioDisciplinasCurso(Disciplina disciplinas[], int qtdDisciplinas) {
    char nomeCurso[50];
    printf("Nome do Curso: ");
    scanf("%s", nomeCurso);

    printf("Disciplinas do curso %s:\n", nomeCurso);
    for (int i = 0; i < qtdDisciplinas; i++) {
        if (strcmp(disciplinas[i].curso, nomeCurso) == 0) {
            printf("Codigo: %d, Nome: %s, Carga Horária: %d\n", disciplinas[i].codigo, disciplinas[i].nome, disciplinas[i].cargaHoraria);
        }
    }
}

void relatorioAlunosDisciplina(Disciplina disciplinas[], int qtdDisciplinas, Aluno alunos[], int qtdAlunos) {
    int codigoDisciplina;
    printf("Codigo da Disciplina: ");
    scanf("%d", &codigoDisciplina);

    Disciplina *disciplina = NULL;
    for (int i = 0; i < qtdDisciplinas; i++) {
        if (disciplinas[i].codigo == codigoDisciplina) {
            disciplina = &disciplinas[i];
            break;
        }
    }

    if (disciplina) {
        printf("Alunos matriculados na disciplina %s:\n", disciplina->nome);
        for (int i = 0; i < disciplina->qtdAlunos; i++) {
            int codigoAluno = disciplina->alunosMatriculados[i];
            for (int j = 0; j < qtdAlunos; j++) {
                if (alunos[j].codigo == codigoAluno) {
                    printf("Codigo: %d, Nome: %s, Curso: %s\n", alunos[j].codigo, alunos[j].nome, alunos[j].curso);
                    break;
                }
            }
        }
    } else {
        printf("Disciplina não encontrada.\n");
    }
}


int main() {
    Aluno alunos[MAX_ALUNOS];
    Disciplina disciplinas[MAX_DISCIPLINAS];
    int qtdAlunos = 0;
    int qtdDisciplinas = 0;

    int opcao;

    do {
        printf("----- Menu -----\n");
        printf("1. Cadastrar Aluno\n");
        printf("2. Cadastrar Disciplina\n");
        printf("3. Matricular Aluno em Disciplina\n");
        printf("4. Imprimir Disciplinas de um Curso\n");
        printf("5. Imprimir Alunos em uma Disciplina\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf(" %d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarAluno(alunos, &qtdAlunos);
                break;
            case 2:
                cadastrarDisciplina(disciplinas, &qtdDisciplinas);
                break;
            case 3:
                matricularAluno(disciplinas, qtdDisciplinas, alunos, qtdAlunos);
                break;
            case 4:
                relatorioDisciplinasCurso(disciplinas, qtdDisciplinas);
                break;
            case 5:
                relatorioAlunosDisciplina(disciplinas, qtdDisciplinas, alunos, qtdAlunos);
                break;
            case 6:
                printf("Saindo...\n");
                break;
            default:
                printf("opcao invalida.\n");
        }
    } while (opcao != 6);

    return 0;
}

