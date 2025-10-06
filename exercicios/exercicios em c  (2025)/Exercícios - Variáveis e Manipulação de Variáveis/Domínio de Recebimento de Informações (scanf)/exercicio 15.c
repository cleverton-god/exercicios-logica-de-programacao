#include <stdio.h>

int main() {
	int ano_nascimento=0;
	int ano_atual=0;
	int idade=0;
	
	printf("digite o seu ano de nascimento \n");
	scanf("%i",&ano_nascimento);
	
	printf("digite o ano de atual \n");
	scanf("%i",&ano_atual);
	
	idade = ano_atual - ano_nascimento;
	
	printf("sua idade e:%i",idade);
	
    return 0;
}

