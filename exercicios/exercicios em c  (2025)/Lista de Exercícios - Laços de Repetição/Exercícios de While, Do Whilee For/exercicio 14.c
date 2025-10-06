#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int dado1 = rand() % 6 + 1;
    int dado2 = rand() % 6 + 1;
    int soma = dado1 + dado2;

    printf("Dado 1: %d\nDado 2: %d\nSoma: %d\n", dado1, dado2, soma);

    if (soma == 7 || soma == 11) {
        printf("Voce ganhou!\n");
    } else {
        printf("Voce perdeu.\n");
    }

    return 0;
}

