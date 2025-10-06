#include <stdio.h>

int main() {
    int numeros[8] = {2, 3, 4, 5, 6, 7, 8, 9};
    int soma_pares = 0, soma_impares = 0;

    for (int i = 0; i < 8; i++) {
        if (numeros[i] % 2 == 0) {
            soma_pares += numeros[i];
        } else {
            soma_impares += numeros[i];
        }
    }

    printf("Soma dos pares: %d\n", soma_pares);
    printf("Soma dos impares: %d\n", soma_impares);

    return 0;
}

