/* Uma lista heterogênea é aquela capaz de armazenar nós com tipos distintos entre si.
Diversas aplicações precisam construir listas heterogêneas, pois necessitam agrupar elementos afins, 
mas não necessariamente iguais. 
Considere uma aplicação que necessita calcular a área total de diferentes formas geométricas, como 
retângulos (base e altura), triângulos (lado a, lado b e lado c) e círculos (raio), agrupados em uma única 
lista encadeada. 
Observe que os dados necessários para cada forma geométrica, e o cálculo para se obter a área são 
distintos entre si.
Para criar uma lista heterogênea, devemos definir 03 novos tipos de struct, representando cada forma 
geométrica, e outro tipo struct para representar, de forma genérica, uma forma geométrica, como por 
exemplo:
Faça um programa que, utilizando uma única Lista Heterogênea, apresente as seguintes opções ao 
usuário:
1 – Cadastrar Retângulo
2 – Cadastrar Triângulo
3 – Cadastrar Círculo
4 – Obter Área dos Retângulos
5 – Obter Área dos Triângulos
6 – Obter Área dos Círculos
7 – Obter Área Total Cadastrada
Obs.: Utilize a Fórmula de Heron para calcular a área do triângulo.
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Definições das estruturas

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
  int tipo;   // 1: retângulo, 2: triângulo, 3: círculo;
  void *info; // ponteiro genérico que aponta para qualquer uma das três structs
  struct FormaGeometrica *prox; // ponteiro para próxima forma
} FormaGeometrica;

// Funções para cálculo de área

Retangulo *criarRetangulo() {
  Retangulo *retangulo = malloc(sizeof(Retangulo));
  if (retangulo == NULL) {
    printf("Erro ao alocar memória para o retângulo.\n");
    exit(EXIT_FAILURE);
  }

  printf("Digite a base do retângulo: ");
  scanf(" %f", &retangulo->base);

  printf("Digite a altura do retângulo: ");
  scanf(" %f", &retangulo->altura);

  return retangulo;
}

float calcularAreaRetangulo(Retangulo *retangulo) {
  return retangulo->base * retangulo->altura;
}

Triangulo *criarTriangulo() {
  Triangulo *triangulo = malloc(sizeof(Triangulo));
  if (triangulo == NULL) {
    printf("Erro ao alocar memória para o triângulo.\n");
    exit(EXIT_FAILURE);
  }

  printf("Digite o lado A do triângulo: ");
  scanf(" %f", &triangulo->ladoA);

  printf("Digite o lado B do triângulo: ");
  scanf(" %f", &triangulo->ladoB);

  printf("Digite o lado C do triângulo: ");
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
    printf("Erro ao alocar memória para o círculo.\n");
    exit(EXIT_FAILURE);
  }

  printf("Digite o raio do círculo: ");
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
    printf("1 - Cadastrar Retângulo\n");
    printf("2 - Cadastrar Triângulo\n");
    printf("3 - Cadastrar Círculo\n");
    printf("4 - Obter Área dos Retângulos\n");
    printf("5 - Obter Área dos Triângulos\n");
    printf("6 - Obter Área dos Círculos\n");
    printf("7 - Obter Área Total Cadastrada\n");
    printf("0 - Sair\n");
    printf("Escolha uma opção: ");
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
      printf("Área dos retângulos: %.2f\n", areaRetangulos);
      break;
    }
    case 5: {
      float areaTriangulos = obterAreaTriangulos(listaFormas);
      printf("Área dos triângulos: %.2f\n", areaTriangulos);
      break;
    }
    case 6: {
      float areaCirculos = obterAreaCirculos(listaFormas);
      printf("Área dos círculos: %.2f\n", areaCirculos);
      break;
    }
    case 7: {
      float areaTotal = obterAreaTotalCadastrada(listaFormas);
      printf("Área total cadastrada: %.2f\n", areaTotal);
      break;
    }
    case 0:
      printf("Encerrando o programa.\n");
      break;
    default:
      printf("Opção inválida.\n");
    }
  } while (opcao != 0);

  // Libera a memória alocada para as formas geométricas
  FormaGeometrica *atual = listaFormas;
  while (atual != NULL) {
    FormaGeometrica *next = atual->prox;
    free(atual->info);
    free(atual);
    atual = next;
  }

  return 0;

