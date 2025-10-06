#include <stdio.h>

int main() {
    int idade;

    printf("Digite a idade: ");
    scanf("%d", &idade);

    if (idade >= 5 && idade <= 7) {
        printf("Categoria: Infantil A (5-7 anos)\n");
    } else if (idade <= 10) {
        printf("Categoria: Infantil B (8-10 anos)\n");
    } else if (idade <= 13) {
        printf("Categoria: Juvenil A (11-13 anos)\n");
    } else if (idade <= 17) {
        printf("Categoria: Juvenil B (14-17 anos)\n");
    } else if (idade >= 18) {
        printf("Categoria: Adulto (18+ anos)\n");
    } else {
        printf("Idade abaixo da mínima para competicao.\n");
    }

    return 0;
}

