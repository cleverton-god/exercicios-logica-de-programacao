#include <stdio.h>

struct Produto {
    char nome[50];
    float preco;
    int quantidade;
};

int main() {
    struct Produto p;

    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", p.nome);
    printf("Digite o preco: ");
    scanf("%f", &p.preco);
    printf("Digite a quantidade: ");
    scanf("%d", &p.quantidade);

    printf("\n--- Produto Cadastrado ---\n");
    printf("Nome: %s\n", p.nome);
    printf("Preco: R$%.2f\n", p.preco);
    printf("Quantidade: %d\n", p.quantidade);

    return 0;
}
