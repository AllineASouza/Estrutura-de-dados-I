/* Uma lista heterog�nea � aquela capaz de armazenar n�s com tipos distintos entre si.
Diversas aplica��es precisam construir listas heterog�neas, pois necessitam agrupar elementos afins, 
mas n�o necessariamente iguais. 
Considere uma aplica��o que necessita calcular a �rea total de diferentes formas geom�tricas, como 
ret�ngulos (base e altura), tri�ngulos (lado a, lado b e lado c) e c�rculos (raio), agrupados em uma �nica 
lista encadeada. 
Observe que os dados necess�rios para cada forma geom�trica, e o c�lculo para se obter a �rea s�o 
distintos entre si.
Para criar uma lista heterog�nea, devemos definir 03 novos tipos de struct, representando cada forma 
geom�trica, e outro tipo struct para representar, de forma gen�rica, uma forma geom�trica, como por 
exemplo:
Fa�a um programa que, utilizando uma �nica Lista Heterog�nea, apresente as seguintes op��es ao 
usu�rio:
1 � Cadastrar Ret�ngulo
2 � Cadastrar Tri�ngulo
3 � Cadastrar C�rculo
4 � Obter �rea dos Ret�ngulos
5 � Obter �rea dos Tri�ngulos
6 � Obter �rea dos C�rculos
7 � Obter �rea Total Cadastrada
Obs.: Utilize a F�rmula de Heron para calcular a �rea do tri�ngulo.
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Defini��es das estruturas

typedef struct Retangulo {
  float base;
  float altura;
} Retangulo;

typedef struct Triangulo {
  float ladoA;
  float ladoB;
  float ladoC;
} Triangulo;

typedef struct Circulo {
  float raio;
} Circulo;

typedef struct FormaGeometrica {
  int tipo;   // 1: ret�ngulo, 2: tri�ngulo, 3: c�rculo;
  void *info; // ponteiro gen�rico que aponta para qualquer uma das tr�s structs
  struct FormaGeometrica *prox; // ponteiro para pr�xima forma
} FormaGeometrica;

// Fun��es para c�lculo de �rea

Retangulo *criarRetangulo() {
  Retangulo *retangulo = malloc(sizeof(Retangulo));
  if (retangulo == NULL) {
    printf("Erro ao alocar mem�ria para o ret�ngulo.\n");
    exit(EXIT_FAILURE);
  }

  printf("Digite a base do ret�ngulo: ");
  scanf(" %f", &retangulo->base);

  printf("Digite a altura do ret�ngulo: ");
  scanf(" %f", &retangulo->altura);

  return retangulo;
}

float calcularAreaRetangulo(Retangulo *retangulo) {
  return retangulo->base * retangulo->altura;
}

Triangulo *criarTriangulo() {
  Triangulo *triangulo = malloc(sizeof(Triangulo));
  if (triangulo == NULL) {
    printf("Erro ao alocar mem�ria para o tri�ngulo.\n");
    exit(EXIT_FAILURE);
  }

  printf("Digite o lado A do tri�ngulo: ");
  scanf(" %f", &triangulo->ladoA);

  printf("Digite o lado B do tri�ngulo: ");
  scanf(" %f", &triangulo->ladoB);

  printf("Digite o lado C do tri�ngulo: ");
  scanf(" %f", &triangulo->ladoC);

  return triangulo;
}
float calcularAreaTriangulo(Triangulo *triangulo) {
  float s = (triangulo->ladoA + triangulo->ladoB + triangulo->ladoC) / 2;
  return sqrt(s * (s - triangulo->ladoA) * (s - triangulo->ladoB) *
              (s - triangulo->ladoC));
}

Circulo *criarCirculo() {
  Circulo *circulo = malloc(sizeof(Circulo));
  if (circulo == NULL) {
    printf("Erro ao alocar mem�ria para o c�rculo.\n");
    exit(EXIT_FAILURE);
  }

  printf("Digite o raio do c�rculo: ");
  scanf("%f", &circulo->raio);

  return circulo;
}
float calcularAreaCirculo(Circulo *circulo) {
  return M_PI * circulo->raio * circulo->raio;
}

float obterAreaRetangulos(FormaGeometrica *listaFormas) {
  float areaTotal = 0;
  FormaGeometrica *atual = listaFormas;
  while (atual != NULL) {
    if (atual->tipo == 1) {
      Retangulo *retangulo = atual->info;
      areaTotal += calcularAreaRetangulo(retangulo);
    }
    atual = atual->prox;
  }
  return areaTotal;
}

float obterAreaTriangulos(FormaGeometrica *listaFormas) {
  float areaTotal = 0;
  FormaGeometrica *atual = listaFormas;
  while (atual != NULL) {
    if (atual->tipo == 2) {
      Triangulo *triangulo = atual->info;
      areaTotal += calcularAreaTriangulo(triangulo);
    }
    atual = atual->prox;
  }
  return areaTotal;
}

float obterAreaCirculos(FormaGeometrica *listaFormas) {
  float areaTotal = 0;
  FormaGeometrica *atual = listaFormas;
  while (atual != NULL) {
    if (atual->tipo == 3) {
      Circulo *circulo = atual->info;
      areaTotal += calcularAreaCirculo(circulo);
    }
    atual = atual->prox;
  }
  return areaTotal;
}

float obterAreaTotalCadastrada(FormaGeometrica *listaFormas) {
  float areaTotal = 0;
  FormaGeometrica *atual = listaFormas;
  while (atual != NULL) {
    if (atual->tipo == 1) {
      Retangulo *retangulo = atual->info;
      areaTotal += calcularAreaRetangulo(retangulo);
    } else if (atual->tipo == 2) {
      Triangulo *triangulo = atual->info;
      areaTotal += calcularAreaTriangulo(triangulo);
    } else if (atual->tipo == 3) {
      Circulo *circulo = atual->info;
      areaTotal += calcularAreaCirculo(circulo);
    }
    atual = atual->prox;
  }
  return areaTotal;
}

int main() {
  int opcao;
  FormaGeometrica *listaFormas = NULL; // Inicializa a lista vazia

  do {
    printf("1 - Cadastrar Ret�ngulo\n");
    printf("2 - Cadastrar Tri�ngulo\n");
    printf("3 - Cadastrar C�rculo\n");
    printf("4 - Obter �rea dos Ret�ngulos\n");
    printf("5 - Obter �rea dos Tri�ngulos\n");
    printf("6 - Obter �rea dos C�rculos\n");
    printf("7 - Obter �rea Total Cadastrada\n");
    printf("0 - Sair\n");
    printf("Escolha uma op��o: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1: {
      Retangulo *retangulo = criarRetangulo();
      FormaGeometrica *novaForma = malloc(sizeof(FormaGeometrica));
      novaForma->tipo = 1;
      novaForma->info = retangulo;
      novaForma->prox = listaFormas;
      listaFormas = novaForma;
      break;
    }
    case 2: {
      Triangulo *triangulo = criarTriangulo();
      FormaGeometrica *novaForma = malloc(sizeof(FormaGeometrica));
      novaForma->tipo = 2;
      novaForma->info = triangulo;
      novaForma->prox = listaFormas;
      listaFormas = novaForma;
      break;
    }
    case 3: {
      Circulo *circulo = criarCirculo();
      FormaGeometrica *novaForma = malloc(sizeof(FormaGeometrica));
      novaForma->tipo = 3;
      novaForma->info = circulo;
      novaForma->prox = listaFormas;
      listaFormas = novaForma;
      break;
    }
    case 4: {
      float areaRetangulos = obterAreaRetangulos(listaFormas);
      printf("�rea dos ret�ngulos: %.2f\n", areaRetangulos);
      break;
    }
    case 5: {
      float areaTriangulos = obterAreaTriangulos(listaFormas);
      printf("�rea dos tri�ngulos: %.2f\n", areaTriangulos);
      break;
    }
    case 6: {
      float areaCirculos = obterAreaCirculos(listaFormas);
      printf("�rea dos c�rculos: %.2f\n", areaCirculos);
      break;
    }
    case 7: {
      float areaTotal = obterAreaTotalCadastrada(listaFormas);
      printf("�rea total cadastrada: %.2f\n", areaTotal);
      break;
    }
    case 0:
      printf("Encerrando o programa.\n");
      break;
    default:
      printf("Op��o inv�lida.\n");
    }
  } while (opcao != 0);

  // Libera a mem�ria alocada para as formas geom�tricas
  FormaGeometrica *atual = listaFormas;
  while (atual != NULL) {
    FormaGeometrica *next = atual->prox;
    free(atual->info);
    free(atual);
    atual = next;
  }

  return 0;

