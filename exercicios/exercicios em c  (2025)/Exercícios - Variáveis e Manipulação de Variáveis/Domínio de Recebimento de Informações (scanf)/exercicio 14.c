#include <stdio.h>

int main() {
	float valor=0;
	float valorcomdesconto=0;
	
	printf("digite o valor para o desconto\n");
	scanf("%f",&valor);
	
	valorcomdesconto=valor*0.85;
	
	printf("valor com desconto:%.2f",valorcomdesconto);
	
    return 0;
}

