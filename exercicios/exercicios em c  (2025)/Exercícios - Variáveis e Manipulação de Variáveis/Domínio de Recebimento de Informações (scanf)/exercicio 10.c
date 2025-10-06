#include <stdio.h>

int main() {
	float dinheiro=0;
	float aumento=0;
	
	
	printf("digite um numero para um aumento de 10%\n");
	scanf("%f",&dinheiro);
	
	aumento=dinheiro*1.10;
	
	printf("dinheiro com aumento:%.2f",aumento);

    return 0;
}

