#include <stdio.h>

int main() {
	float valor_em_reais=0;
	float valor_em_dolares=0;
	float cotacao_do_dolar=0;
	
	printf("digite o valor em reais\n");
	scanf("%f",&valor_em_reais);
	printf("digite a cotacao do dolar\n");
	scanf("%f",&cotacao_do_dolar);
	

	valor_em_dolares = valor_em_reais / cotacao_do_dolar;
	
	printf("o valor e:%.2f dolares",valor_em_dolares);
	
    return 0;
}

