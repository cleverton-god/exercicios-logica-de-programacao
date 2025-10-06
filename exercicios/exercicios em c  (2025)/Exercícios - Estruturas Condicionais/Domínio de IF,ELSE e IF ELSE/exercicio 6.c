#include <stdio.h>

int main() {
    int ano_nascimento, idade;
    
  
    printf("Digite o ano de nascimento: ");
    scanf("%d", &ano_nascimento);

    idade = 2025 - ano_nascimento;

    printf("Idade: %d anos\n", idade);

    if (idade >= 16) {
        printf("Pode votar.\n");
    } else {
        printf("Não pode votar.\n");
    }

    if (idade >= 18) {
        printf("Pode dirigir.\n");
    } else {
        printf("Não pode dirigir.\n");
    }

    return 0;
}

