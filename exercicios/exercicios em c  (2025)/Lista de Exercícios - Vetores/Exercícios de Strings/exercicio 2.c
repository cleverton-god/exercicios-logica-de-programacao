#include <stdio.h>

int main(){
	char nome[30];
	printf("Digite seu nome completo: ");
	fgets(nome, 30, stdin);
	printf("seu nome: %s", nome);
	return 0;
}

