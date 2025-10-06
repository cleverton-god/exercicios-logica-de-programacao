#include <stdio.h>
#include <string.h>

struct Livro {
    char titulo[50];
    char autor[50];
    int anoPublicacao;
};

struct Livro criarLivro() {
    struct Livro l;

    printf("Digite o titulo do livro: ");
    scanf(" %[^\n]", l.titulo);

    printf("Digite o autor do livro: ");
    scanf(" %[^\n]", l.autor);

    printf("Digite o ano de publicacao: ");
    scanf("%d", &l.anoPublicacao);

    return l;
}

int main() {
    struct Livro livro = criarLivro();

    printf("\n--- Dados do Livro ---\n");
    printf("Titulo: %s\n", livro.titulo);
    printf("Autor: %s\n", livro.autor);
    printf("Ano: %d\n", livro.anoPublicacao);

    return 0;
}
