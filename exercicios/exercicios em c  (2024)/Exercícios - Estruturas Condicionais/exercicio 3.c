#include <stdio.h>

int main() {
    int ano_nascimento, ano_atual = 2024; 
    printf("Digite seu ano de nascimento: ");
    scanf("%d", &ano_nascimento);
    
    int idade_atual = ano_atual - ano_nascimento;

    if (idade_atual >= 16) {
        printf("Voce pode votar.\n");
    } else {
        printf("Voce nao pode votar.\n");
    }

    if (idade_atual >= 18) {
        printf("Voce pode dirigir.\n");
    } else {
        printf("Voce nao pode dirigir.\n");
    }

    return 0;
}

