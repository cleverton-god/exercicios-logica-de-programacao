#include <stdio.h>

int main() {
    int numero, maior;

    printf("Digite um numero: ");
    scanf("%d", &maior);

    for (int i = 1; i < 5; i++) {
        printf("Digite outro numero: ");
        scanf("%d", &numero);

        if (numero > maior) {
            maior = numero;
        }
    }

    printf("O maior numero digitado foi: %d\n", maior);
    return 0;
}

