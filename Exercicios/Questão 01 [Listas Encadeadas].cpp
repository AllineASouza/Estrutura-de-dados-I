/* Quest�o 1 [Listas Encadeadas]
Considere um site de busca de conte�dos que possua uma cole��o de arquivos torrent disponibilizados 
para download dos usu�rios. Considerando que as informa��es dos arquivos torrent (nome do conte�do 
e link para download) s�o armazenados em uma estrutura de dados do tipo lista simplesmente 
encadeada, fa�a um programa que dado o nome de um conte�do, busque e imprima o link
correspondente, e ap�s isso, mova o n� que cont�m o nome buscado para o in�cio da lista, de forma que 
este possa ser encontrado mais rapidamente na pr�xima vez que for buscado.
Fa�a tamb�m uma fun��o para cadastro de arquivos no site e uma fun��o para imprimir todos os 
arquivos da mantidos na lista.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  char nome[100];
  char link[200];
  struct Node *prox;
} Node;

int interface() {
  printf("\n1 - Inserir arquivo\n");
  printf("2 - Buscar arquivo por nome e mover para o in�cio\n");
  printf("3 - Imprimir arquivos\n");
  printf("0 - Sair\n");
  int op;
  do {
    printf("Escolha uma das Opcoes Acima: \n");
    scanf("%d", &op);
    // Limpeza do buffer de entrada
    while (getchar() != '\n');
  } while ((op < 0) || (op > 3));
  return op;
}

int validarLink(char *link) {
  char *prefixo = "http://";
  int i;
  for (i = 0; i < 7; i++) { // Percorre os primeiros 7 caracteres do link e do prefixo
    if (link[i] != prefixo[i]) { // Se algum caractere for diferente, retorna 0
      return 0; // Link inv�lido
    }
  }
  return 1; // Link v�lido (come�a com "http://")
}
/*int validarLink(char *link) {
  char *prefixo = "http://";
//Esta linha compara os primeiros caracteres da string linkcom o prefixo "http://". A fun��o strncmp � usada para comparar os primeiros strlen(prefixo)
//caracteres de linkcom o conte�do de prefixo. Se essas duas strings forem iguais, strncmpr e torna 0, o que significa que o link come�a com "http://".
  if (strncmp(link, prefixo, strlen(prefixo)) == 0) {
    return 1; // Link v�lido (come�a com "http://")
  } else {
    return 0; // Link inv�lido
  }
}
*/
Node *inserirArquivo(Node **lista) {
  Node *novo = (Node *)malloc(sizeof(Node));
  printf("Digite o nome do arquivo: ");
  scanf(" %[^\n]", novo->nome);

  char link[200];
  do {
    printf("Digite o link do arquivo (deve come�ar com 'http://'): ");
    scanf(" %[^\n]", link);
  } while (!validarLink(link));
  strcpy(novo->link, link);
  novo->prox = NULL; // Definir pr�ximo como NULL para inser��o no final

  // Caso especial: lista vazia
//e a lista estiver vazia (ou seja, *lista� NULL), o novo n� se torna o primeiro n� da lista, e *lista� atualizado para apontar para o novo n�.
  if (*lista == NULL) {
    *lista = novo;
  } else {
    // Encontrar o �ltimo n� da lista
//Caso geral: lista n�o vazia : Se a lista n�o estiver vazia, o c�digo percorre a lista para encontrar o �ltimo n�. Isso � feito usando um loop whileque verifica se o campo proxdo n� atual n�o � NULL. Quando o �ltimo n� � encontrado (ou seja, quando ultimo->prox� NULL), o novo n� � adicionado como o pr�ximo n� do �ltimo n� encontrado.
    Node *ultimo = *lista;
    while (ultimo->prox != NULL) {
      ultimo = ultimo->prox;
    }

    // Adicionar novo n� no final
    ultimo->prox = novo;
  }

  return novo;
}
void buscarEAtualizar(Node **lista) {
  char nomeBuscado[100];
  printf("Digite o nome do arquivo a ser buscado: ");
  scanf(" %[^\n]", nomeBuscado);
  Node *atual = *lista;
  Node *anterior = NULL;

  while (atual != NULL) {
//Compare o nome do arquivo atual( atual->nome) com o nome do arquivo buscado( nomeBuscado) usando a fun��o strcmp. Se for igual, significa que o arquivo foi encontrado na lista.
    if (strcmp(atual->nome, nomeBuscado) == 0) {
      printf("Nome: %s\n", atual->nome);
      printf("Link: %s\n", atual->link);

//Esta parte do c�digo lida com a reorganiza��o da lista. Se o arquivo encontrado n�o estiver no in�cio da lista (ou seja, anteriorn�o � NULL), o c�digo a seguir ser� executado.
      if (anterior != NULL) {
        anterior->prox = atual->prox; //O n� anterior agora aponta para o pr�ximo n� do n� atual, removendo assim o n� atual da lista.
        atual->prox = *lista; // O n� atual agora aponta para o in�cio da lista, tornando-se o novo primeiro n�.
        *lista = atual;//O ponteiro da lista � atualizado para apontar para o n� atual, que agora est� no in�cio da lista.
      }

      return;
    }

    anterior = atual;
    atual = atual->prox;
  }

  printf("Arquivo n�o encontrado.\n");
}

void imprimirArquivos(Node *lista) {
  Node *atual = lista;

  while (atual != NULL) {
    printf("Nome: %s\n", atual->nome);
    printf("Link: %s\n", atual->link);
    atual = atual->prox;
  }
}

int main() {
  Node *lista = NULL;

  do {
    switch (interface()) {
    case 1:
      inserirArquivo(&lista);
      break;
    case 2: {
      buscarEAtualizar(&lista);
    } break;
    case 3:
      imprimirArquivos(lista);
      break;
    case 0:
      printf("Encerrando o programa.\n");
      return 0;
    default:
      printf("Op��o inv�lida.\n");
    }
  } while (1);

  return 0;
}

