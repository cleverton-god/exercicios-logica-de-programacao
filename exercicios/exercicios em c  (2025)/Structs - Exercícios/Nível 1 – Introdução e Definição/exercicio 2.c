#include <stdio.h>

struct Livro {
    char titulo[100];
    char autor[50];
    int anoPublicacao;
};

int main() {
    struct Livro l = {"O Senhor dos Aneis", "J.R.R. Tolkien", 1954};

    printf("Titulo: %s\n", l.titulo);
    printf("Autor: %s\n", l.autor);
    printf("Ano de Publicacao: %d\n", l.anoPublicacao);

    return 0;
}
