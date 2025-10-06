#include <stdio.h>

int main() {
    int numeros[5] = {1, 2, 3, 4, 5};

    printf("Vetor original: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numeros[i]);
    }

    printf("\nVetor invertido: ");
    for (int i = 4; i >= 0; i--) {
        printf("%d ", numeros[i]);
    }

    return 0;
}

