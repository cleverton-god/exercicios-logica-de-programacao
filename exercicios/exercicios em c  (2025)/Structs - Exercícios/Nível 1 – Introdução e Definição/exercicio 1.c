#include <stdio.h>
#include <string.h> 

struct Pessoa {
    char nome[50];
    int idade;
};

int main() {
    struct Pessoa p;

    strcpy(p.nome, "Joao Silva");
    p.idade = 25;

    printf("Nome: %s\n", p.nome);
    printf("Idade: %d anos\n", p.idade);

    return 0;
}
