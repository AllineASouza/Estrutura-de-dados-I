/* Quest�o 02 [Exclus�o em uma Lista]
Fa�a um programa que armazene dinamicamente (atrav�s de estrutura de lista encadeada) registros de
Artigos Cient�ficos de um Departamento (Autor, T�tulo, �rea de Conhecimento, Ano de Publica��o).
a) Desenvolva uma fun��o que retorne a quantidade de registros alocados na lista;
b) Desenvolva uma fun��o que realize a impress�o do registro que esteja o mais pr�ximo poss�vel
do meio da lista.
c) Desenvolva uma fun��o que realize a impress�o de todos os registros cadastrados.
d) Desenvolva uma fun��o que realize a impress�o somente das publica��es entre um per�odo de
anos escolhidos pelo usu�rio.
Obs: Os requisitos C e D devem compartilhar a mesma rotina de impress�o de dados.
e) Desenvolva uma fun��o que realize a exclus�o de um determinado registro da lista. Para isto,
solicite ao usu�rio o �T�tulo do Artigo� a ser eliminado.
Obs.: N�o se esque�a de utilizar o comando free(ponteiro) para realizar a libera��o de mem�ria. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DESCRICAO 100

typedef struct Artigo {
    char autor[MAX_DESCRICAO];
    char titulo[MAX_DESCRICAO];
    char area_Conhecimento[MAX_DESCRICAO];
    int ano;
    struct Artigo* prox;
} Artigo;

int interface() {
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\t\t\tMENU\t\n\n1 - Cadastrar Artigo\n");
    printf("2 - Imprimir Artigo Proximo ao Meio da Lista Total\n");
    printf("3 - Imprimir Todos os Artigos Cadastrados\n");
    printf("4 - Consultar por per�odo de ano\n");
    printf("5 - Excluir Artigo\n");
    printf("0 - ENCERRAR PROGRAMA\n");
    int op;
    do {
        printf("Escolha uma das Opcoes Acima: \n");
        scanf(" %d", &op);
    } while ((op < 0) || (op > 5));
    return op;
}

// Fun��o para contar o n�mero de artigos cadastrados
int contAtigo(int cont) {
    cont++;
  //  printf("Artigo de numero %d cadastrado com sucesso\n", cont);
    return cont;
}

// Fun��o para cadastrar artigo
Artigo* criarAtigo(Artigo* d, int* cont) {
    Artigo* nv = (Artigo*)malloc(sizeof(Artigo)); // Aloca mem�ria para um novo artigo.
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\t\t\tCADASTRANDO ARTIGO\t\n\nAutor: ");
    scanf(" %[^\n]s", nv->autor);
    printf("Titulo: ");
    scanf(" %[^\n]s", nv->titulo);
    printf("Area de Conhecimento: ");
    scanf(" %[^\n]s", nv->area_Conhecimento);
    printf("Ano de Publicacao: ");
    scanf(" %d", &nv->ano);
    nv->prox = d; // Adicionado o novo artigo no in�cio da lista encadeada.
    *cont = contAtigo(*cont); // Atualiza o contador de artigos.
    return nv;
}

// Fun��o para mostrar o artigo do meio da lista
void imprimirMeio(Artigo* d, int cont) {
    int metade = 0, x = 0;
    metade = cont / 2;
    printf("\n=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\t\tLISTA DE ARTIGOS CADASTRADOS NA METADE\t\n");
    //Inicia um loop while que percorre uma lista de artigos. O loop continua enquanto o ponteiro dn�o for nulo, ou seja, enquanto houver artigos a serem percorridos.
	while (d) {
	//Verifique se a vari�vel x(que � usada para contar os artigos) � igual � posi��o da metade da lista ( metade). Se for igual, significa que encontramos o artigo do meio.
        if (metade == x) {
            printf("Autor: %s\nTitulo: %s\nArea de Conhecimento: %s\nAno: %d\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n", d->autor, d->titulo, d->area_Conhecimento, d->ano);
            break;
        }
    //Avan�a para o pr�ximo artigo da lista, movendo o ponteiro dpara o pr�ximo elemento da lista encadeada.
        d = d->prox;
        x++;
    }
}

// Fun��o para imprimir todos os artigos cadastrados
void imprimirTodos(Artigo* d) {
    printf("\n=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\t\tLISTA DE ARTIGOS CADASTRADOS\t\n");
    while (d) {
        printf("Autor: %s\nTitulo: %s\nArea de Conhecimento: %s\nAno: %d\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n", d->autor, d->titulo, d->area_Conhecimento, d->ano);
        d = d->prox;
    }
}

// Fun��o para imprimir os artigos cadastrados em determinado intervalo de tempo
void imprimirPorPeriodo(Artigo* d, int cont) {
    int anoInicial = 0, anoFinal = 0;
    printf("Informe o Ano Inicial e Final: ");
    scanf(" %d %d", &anoInicial, &anoFinal);
    printf("\n=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\t\tLISTA DE ARTIGOS CADASTRADOS NESSE PERIODO\t\n");
    while (d) {
        if ((d->ano >= anoInicial) && (d->ano <= anoFinal)) {
            printf("Autor: %s\nTitulo: %s\nArea de Conhecimento: %s\nAno: %d\n", d->autor, d->titulo, d->area_Conhecimento, d->ano);
        }
        d = d->prox;
    }
}

// Fun��o para excluir artigo
void excluirPorTitulo(Artigo** d) {
    char busca[MAX_DESCRICAO];
    printf("Informe o Titulo do Artigo Buscado:\n");
    scanf(" %[^\n]s", busca);
    Artigo* agr = *d; //Crie um ponteiro agr e inicialize-o com o in�cio da lista encadeada *d, que � apontado pelo ponteiro duplo **d.
    Artigo* ant = NULL; // Inicializa um ponteiro ant como NULL. Este ser� usado para manter o rastreamento do elemento anterior na lista.
    int achou = 0;
    while (agr) {
        if (strcmp(agr->titulo, busca) == 0) { // Se eles forem iguais (retorna 0), significa que o artigo foi encontrado.
            achou = 1;
        // Se for o primeiro, atualiza o in�cio da lista *d para apontar para o pr�ximo artigo, ignorando o artigo a ser exclu�do.
            if (ant == NULL) {
                *d = agr->prox;
            } else {
                ant->prox = agr->prox;
            }
            free(agr); //Libera a mem�ria alocada para o artigo exclu�do 
            printf("Artigo excluido com sucesso\n");
        }
        ant = agr; //Atualiza o ponteiro ant para apontar para o artigo atual, que se tornar� o "artigo anterior" na pr�xima itera��o.
        agr = agr->prox; //Mova o ponteiro agr para apontar para o pr�ximo artigo na lista.
    }
    if (!achou) {
        printf("Artigo buscado n�o encontrado\n");
        return;
    }
}

int main() {
    Artigo* d = NULL;
    int contartigo = 0;
    do {
        switch (interface()) {
            case 1:
                d = criarAtigo(d, &contartigo);
                break;
            case 2:
                    imprimirMeio(d, contartigo);
                break;
            case 3:
                    imprimirTodos(d);
                break;
            case 4:
                    imprimirPorPeriodo(d, contartigo);
                break;
            case 5:
                    excluirPorTitulo(&d);
                break;
            case 0:
                printf("Finalizando Programa\n");
                return 0;
        }
    } while (1);
    return 0;
}

