#include <stdio.h>
#include <string.h>

struct Pessoa {
    char nome[50];
    int idade;
};

int main() {
    struct Pessoa pessoas[3];
    int i;

    for (i = 0; i < 3; i++) {
        printf("\nPessoa %d\n", i + 1);
        printf("Digite o nome: ");
        scanf(" %[^\n]", pessoas[i].nome);
        printf("Digite a idade: ");
        scanf("%d", &pessoas[i].idade);
    }

    printf("\n--- Lista de Pessoas ---\n");
    for (i = 0; i < 3; i++) {
        printf("Pessoa %d: %s - %d anos\n", i + 1, pessoas[i].nome, pessoas[i].idade);
    }

    return 0;
}
