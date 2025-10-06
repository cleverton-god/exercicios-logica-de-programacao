#include <stdio.h>
#include <string.h>

struct Pessoa {
    char nome[50];
    int idade;
};

void imprimirPessoa(struct Pessoa p) {
    printf("\n--- Dados da Pessoa ---\n");
    printf("Nome: %s\n", p.nome);
    printf("Idade: %d anos\n", p.idade);
}

int main() {
    struct Pessoa p;

    printf("Digite o nome: ");
    scanf(" %[^\n]", p.nome);

    printf("Digite a idade: ");
    scanf("%d", &p.idade);

    imprimirPessoa(p);

    return 0;
}
