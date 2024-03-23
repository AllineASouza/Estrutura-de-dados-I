#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

typedef struct {
	float ValorEmprestado;
	int Prazo;
	float TaxaJuros;
} Proposta;

int main() {
	
	setlocale(LC_ALL, "Portuguese");
	printf("Simulador de Empr�stimo Financeiro\n");
	printf("Digite um valor de empr�stimo negativo para sair.\n");

	Proposta emprestimo;
	
	do {
		printf("\nDigite o valor do empr�stimo (R$): ");
		scanf(" %f", &emprestimo.ValorEmprestado);
		
		if (emprestimo.ValorEmprestado < 0){
			printf("Encerrando o programa...\n");
			break;
		}
		
		printf("Digite o prazo (em meses): ");
		scanf(" %d", &emprestimo.Prazo);
		
		printf("Digite a taxa de juros (em %%): ");
		scanf(" %f", &emprestimo.TaxaJuros);
		
		float taxaMensal = emprestimo.TaxaJuros / 100; 
		float valorTotalPago = 0.0;
		
		printf("\n\t--- Detalhamento das Parcelas ---\n\n");
		
		for (int i = 0; i < emprestimo.Prazo; i++) {
			float valorAcumulado = emprestimo.ValorEmprestado * pow(1 + taxaMensal, i);
			// C�lculo dos juros para o m�s atual
			float valorParcela = emprestimo.ValorEmprestado * pow(1 + taxaMensal,i + 1) -valorAcumulado;
			valorTotalPago += valorParcela;
			
			printf("M�s %d: Parcela: R$ %.2f | Juros: R$ %.2f\n", i+1, valorParcela, valorAcumulado);
		}
		printf("\nJuros totais pagos no empr�stimo: %.2f\n",valorTotalPago);
		
		//	system("cls");
	} while (emprestimo.ValorEmprestado > 0);
	
	printf("\n");

return 0;
}

