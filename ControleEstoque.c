#include <stdio.h>
#include <string.h>
#include <locale.h>

struct cadastro{
	int codigo;
	char nome[10];
	int quantidade;
	float preco_unitario;
};

int main() {
	setlocale(LC_ALL, "Portuguese");
	struct cadastro pecas[10];
	float valor_total = 0;
	float maior_valor = 0;
	float valor_atual = 0;
	int id_maior_valor = 0;
	int i;
	
	for (i = 0;i < 10; i++) {
		printf("Digite o codigo da peça %d: ", i+1);
		scanf("%d", &pecas[i].codigo);
		
		printf("Digite o nome da peça %d: ", i+1);
		scanf("%s", &pecas[i].nome);
		
		printf("Digite a quantidade de peças %d: ", i+1);
		scanf("%d", &pecas[i].quantidade);
		
		printf("Digite o preço unitário da peça %d: ", i+1);
		scanf("%f", &pecas[i].preco_unitario);
	}
	
	for (i = 0; i < 10;i++) {
		valor_total += pecas[i].quantidade * pecas[i].preco_unitario;
	}
	printf("\nValor total do estoque é igual a: %.2f\n", valor_total);
	
	maior_valor = pecas[0].quantidade * pecas[0].preco_unitario;
	for(i = 1;i < 10;i++) {
		valor_atual = pecas[i].quantidade * pecas[i].preco_unitario;
		if (valor_atual > maior_valor) {
			id_maior_valor = i;
			maior_valor = valor_atual;
		}
	}
	printf("A peça com maior valor em estoque é: código %d, nome %s\n", pecas[id_maior_valor].codigo, pecas[id_maior_valor].nome);
	
	return 0;
}

