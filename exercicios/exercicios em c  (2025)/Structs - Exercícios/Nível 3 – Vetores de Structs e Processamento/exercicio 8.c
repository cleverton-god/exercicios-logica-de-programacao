#include <stdio.h>
#include <string.h>

struct Produto {
    char nome[50];
    float preco;
    int quantidade;
};

int main() {
    struct Produto produtos[5];
    int i;
    float soma = 0, media;

    for (i = 0; i < 5; i++) {
        printf("\nProduto %d\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", produtos[i].nome);
        printf("Preco: ");
        scanf("%f", &produtos[i].preco);
        printf("Quantidade: ");
        scanf("%d", &produtos[i].quantidade);

        soma += produtos[i].preco;
    }

    media = soma / 5;

    printf("\nMedia dos precos: %.2f\n", media);

    return 0;
}
