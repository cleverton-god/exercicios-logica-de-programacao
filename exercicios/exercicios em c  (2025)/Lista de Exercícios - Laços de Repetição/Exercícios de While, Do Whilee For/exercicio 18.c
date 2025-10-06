#include <stdio.h>

int main() {
    int numero, soma = 0;

    for (int i = 0; i < 5; i++) {
        printf("Digite um numero: ");
        scanf("%d", &numero);
        if (numero % 2 == 0) {
            soma += numero;
        }
    }

    printf("Soma dos numeros pares: %d\n", soma);
    return 0;
}

