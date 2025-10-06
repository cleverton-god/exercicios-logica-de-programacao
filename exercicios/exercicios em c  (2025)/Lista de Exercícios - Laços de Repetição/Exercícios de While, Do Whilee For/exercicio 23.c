#include <stdio.h>

int main() {
    int numero, pares = 0, impares = 0;

    for (int i = 0; i < 6; i++) {
        printf("Digite um numero inteiro: ");
        scanf("%d", &numero);

        if (numero % 2 == 0) {
            pares++;
        } else {
            impares++;
        }
    }

    printf("Quantidade de numeros pares: %d\n", pares);
    printf("Quantidade de numeros impares: %d\n", impares);
    return 0;
}

