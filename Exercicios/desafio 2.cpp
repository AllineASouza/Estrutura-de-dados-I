
#include <stdio.h>
#include <locale.h>

#define MAX_PRODUTOS 100

// aqui vai definir um novo tipo Produto
typedef struct {
    int codigoBarras;
    char descricao[50];
    int quantidadeEstoque;
    float valorUnitario;
} Produto;

int main() {
	
	setlocale(LC_ALL, "Portuguese");
// aqui declara as variaveis 
    Produto produtos[MAX_PRODUTOS]; 
    int numProdutos = 0; // contadora de produtos
    int codigoBarras, quantidade;
    float valorRecebido;
    float valorTotal = 0.0;

    // Cadastro de produtos
    printf("Cadastro de produto!\n\n");
    printf("Informe o C�digo de Barras (negativo para sair): ");
    scanf(" %d", &codigoBarras);

/* enquanto o c�digo de barras informado for maior ou igual a zero e o 
n�mero de produtos cadastrados for menor que MAX_PRODUTOS.*/
    while (codigoBarras >= 0 && numProdutos < MAX_PRODUTOS) {
// Aqui armazena o codigo de barra.
		produtos[numProdutos].codigoBarras = codigoBarras;

        printf("Informe a Descri��o: ");
        scanf(" %[^\n]s", produtos[numProdutos].descricao);

        printf("Informe a Quantidade em Estoque: ");
        scanf(" %d", &produtos[numProdutos].quantidadeEstoque);

        printf("Informe o Valor Unit�rio: ");
        scanf(" %f", &produtos[numProdutos].valorUnitario);

        numProdutos++;

        printf("\nInforme o C�digo de Barras (negativo para sair): ");
        scanf(" %d", &codigoBarras);
    }
        
    printf("\nModo de vendas!\n\n");
    printf("Informe o C�digo de Barras do produto a ser vendido (negativo para sair): ");
    scanf(" %d", &codigoBarras);

/* Dentro do loop declarei as vari�veis.
Realiza um loop pelos produtos cadastrados utilizando uma vari�vel i. */
    while (codigoBarras >= 0) {
        int encontrado = 0;
        int indiceProduto = 0;
/* Verifica se o c�digo de barras do produto atual (produtos[i].codigoBarras) � 
igual ao c�digo de barras informado.
Se for igual, atribui 1 � vari�vel encontrado, armazena o �ndice do produto (i) na vari�vel 
indiceProduto e interrompe o loop usando break.*/
        for (int i = 0; i < numProdutos; i++) {
            if (produtos[i].codigoBarras == codigoBarras) {
                encontrado = 1;
                indiceProduto = i;
                break;
            }
        }

        if (encontrado) {
            printf("\nInforma��es do produto!\n\n");
            printf("C�digo de Barras: %d\n", produtos[indiceProduto].codigoBarras);
            printf("Descri��o: %s\n", produtos[indiceProduto].descricao);
            printf("Quantidade em Estoque: %d\n", produtos[indiceProduto].quantidadeEstoque);
            printf("Valor Unit�rio: R$%.2f\n", produtos[indiceProduto].valorUnitario);

            printf("\nInforme a Quantidade desejada: ");
            scanf(" %d", &quantidade);

            if (quantidade <= produtos[indiceProduto].quantidadeEstoque) {
                float valorVenda = quantidade * produtos[indiceProduto].valorUnitario;
                valorTotal += valorVenda;
                produtos[indiceProduto].quantidadeEstoque -= quantidade;

                printf("\nVenda realizada!\n");
                
            } else {
                printf("\nQuantidade insuficiente em estoque.\n");
            }
        } else {
            printf("\nProduto n�o encontrado.\n");
        }

        printf("\nInforme o C�digo de Barras do produto a ser vendido (negativo para sair): ");
        scanf(" %d", &codigoBarras);
    }

    printf("\nResumo da venda!\n");
    printf("Valor total da venda: R$%.2f\n", valorTotal);
	printf("Valor recebido: R$");
	scanf(" %f", &valorRecebido);
	printf("\nTroco: R$%.2f\n", valorRecebido - valorTotal);
	
    return 0;
}



