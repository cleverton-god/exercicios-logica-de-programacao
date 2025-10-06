#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numeros_sorteados[6], numeros_usuario[6], acertos = 0;

    srand(time(NULL));

    printf("Digite 6 numeros entre 1 e 60:\n ");
    for (int i = 0; i < 6; i++) {
        scanf("%d", &numeros_usuario[i]);
    }

    printf("Numeros sorteados: ");
    for (int i = 0; i < 6; i++) {
        numeros_sorteados[i] = rand() % 60 + 1;
        printf("%d ", numeros_sorteados[i]);
    }
    printf("\n");

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (numeros_usuario[i] == numeros_sorteados[j]) {
                acertos++;
            }
        }
    }

    printf("Voce acertou %d numeros!\n", acertos);

    return 0;
}

