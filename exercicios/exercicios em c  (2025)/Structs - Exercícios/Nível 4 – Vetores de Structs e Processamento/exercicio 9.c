#include <stdio.h>
#include <string.h>

struct Livro {
    char titulo[50];
    char autor[50];
    int anoPublicacao;
};

int main() {
    struct Livro livros[5];
    char busca[50];
    int i, encontrado = 0;

    printf("Cadastro de Livros:\n");
    for (i = 0; i < 5; i++) {
        printf("\nLivro %d:\n", i + 1);
        printf("Titulo: ");
        scanf(" %[^\n]", livros[i].titulo);
        printf("Autor: ");
        scanf(" %[^\n]", livros[i].autor);
        printf("Ano de Publicacao: ");
        scanf("%d", &livros[i].anoPublicacao);
    }

    printf("\nDigite o titulo do livro que deseja buscar: ");
    scanf(" %[^\n]", busca);

    for (i = 0; i < 5; i++) {
        if (strcmp(livros[i].titulo, busca) == 0) {
            printf("\nLivro encontrado!\n");
            printf("Titulo: %s\n", livros[i].titulo);
            printf("Autor: %s\n", livros[i].autor);
            printf("Ano de Publicacao: %d\n", livros[i].anoPublicacao);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("\nLivro nao encontrado.\n");
    }

    return 0;
}
