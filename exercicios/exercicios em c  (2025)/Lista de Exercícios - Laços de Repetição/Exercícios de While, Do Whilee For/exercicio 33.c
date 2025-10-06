#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numero, palpite;

    srand(time(NULL));
    numero = rand() % 10 + 1;

    do {
        printf("Adivinhe o numero entre 1 e 10: ");
        scanf("%d", &palpite);

        if (palpite < numero) {
            printf("Tente um numero maior.\n");
        } else if (palpite > numero) {
            printf("Tente um numero menor.\n");
        }
    } while (palpite != numero);

    printf("Parabens! Voce acertou o numero %d.\n", numero);
    return 0;
}
