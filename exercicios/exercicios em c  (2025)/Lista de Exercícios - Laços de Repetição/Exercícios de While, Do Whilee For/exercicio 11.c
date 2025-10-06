#include <stdio.h>

int main() {
	float soma=0;
	float media=0;
	float numero=0;
	
	printf("digite 5 numeros para sabe a media:\n");
	
	for (int i = 0; i <= 4; i++) {
	
	scanf("%f", &numero);
	soma += numero;
	}
	media = (soma/5);
	printf("a media e:%.2f",media);
	return 0;
}
