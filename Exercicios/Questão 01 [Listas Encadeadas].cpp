/* Questão 1 [Listas Encadeadas]
Considere um site de busca de conteúdos que possua uma coleção de arquivos torrent disponibilizados 
para download dos usuários. Considerando que as informações dos arquivos torrent (nome do conteúdo 
e link para download) são armazenados em uma estrutura de dados do tipo lista simplesmente 
encadeada, faça um programa que dado o nome de um conteúdo, busque e imprima o link
correspondente, e após isso, mova o nó que contém o nome buscado para o início da lista, de forma que 
este possa ser encontrado mais rapidamente na próxima vez que for buscado.
Faça também uma função para cadastro de arquivos no site e uma função para imprimir todos os 
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
  printf("2 - Buscar arquivo por nome e mover para o início\n");
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
      return 0; // Link inválido
    }
  }
  return 1; // Link válido (começa com "http://")
}
/*int validarLink(char *link) {
  char *prefixo = "http://";
//Esta linha compara os primeiros caracteres da string linkcom o prefixo "http://". A função strncmp é usada para comparar os primeiros strlen(prefixo)
//caracteres de linkcom o conteúdo de prefixo. Se essas duas strings forem iguais, strncmpr e torna 0, o que significa que o link começa com "http://".
  if (strncmp(link, prefixo, strlen(prefixo)) == 0) {
    return 1; // Link válido (começa com "http://")
  } else {
    return 0; // Link inválido
  }
}
*/
Node *inserirArquivo(Node **lista) {
  Node *novo = (Node *)malloc(sizeof(Node));
  printf("Digite o nome do arquivo: ");
  scanf(" %[^\n]", novo->nome);

  char link[200];
  do {
    printf("Digite o link do arquivo (deve começar com 'http://'): ");
    scanf(" %[^\n]", link);
  } while (!validarLink(link));
  strcpy(novo->link, link);
  novo->prox = NULL; // Definir próximo como NULL para inserção no final

  // Caso especial: lista vazia
//e a lista estiver vazia (ou seja, *listaé NULL), o novo nó se torna o primeiro nó da lista, e *listaé atualizado para apontar para o novo nó.
  if (*lista == NULL) {
    *lista = novo;
  } else {
    // Encontrar o último nó da lista
//Caso geral: lista não vazia : Se a lista não estiver vazia, o código percorre a lista para encontrar o último nó. Isso é feito usando um loop whileque verifica se o campo proxdo nó atual não é NULL. Quando o último nó é encontrado (ou seja, quando ultimo->proxé NULL), o novo nó é adicionado como o próximo nó do último nó encontrado.
    Node *ultimo = *lista;
    while (ultimo->prox != NULL) {
      ultimo = ultimo->prox;
    }

    // Adicionar novo nó no final
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
//Compare o nome do arquivo atual( atual->nome) com o nome do arquivo buscado( nomeBuscado) usando a função strcmp. Se for igual, significa que o arquivo foi encontrado na lista.
    if (strcmp(atual->nome, nomeBuscado) == 0) {
      printf("Nome: %s\n", atual->nome);
      printf("Link: %s\n", atual->link);

//Esta parte do código lida com a reorganização da lista. Se o arquivo encontrado não estiver no início da lista (ou seja, anteriornão é NULL), o código a seguir será executado.
      if (anterior != NULL) {
        anterior->prox = atual->prox; //O nó anterior agora aponta para o próximo nó do nó atual, removendo assim o nó atual da lista.
        atual->prox = *lista; // O nó atual agora aponta para o início da lista, tornando-se o novo primeiro nó.
        *lista = atual;//O ponteiro da lista é atualizado para apontar para o nó atual, que agora está no início da lista.
      }

      return;
    }

    anterior = atual;
    atual = atual->prox;
  }

  printf("Arquivo não encontrado.\n");
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
      printf("Opção inválida.\n");
    }
  } while (1);

  return 0;
}

