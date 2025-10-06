#include <stdio.h>

int main() {
    int numero, contador = 0;

    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &numero);

    if (numero <= 0) {
        printf("Numero invalido!\n");
        return 1;
    }

    printf("Divisores de %d: ", numero);
    for (int i = 1; i <= numero; i++) {
        if (numero % i == 0) {
            printf("%d ", i);
            contador++;
        }
    }

    printf("\nTotal de divisores: %d\n", contador);
    return 0;
}

