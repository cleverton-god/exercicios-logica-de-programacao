#include <stdio.h>

int main() {
    int numero, invertido = 0;

    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &numero);

    if (numero < 0) {
        printf("Por favor, insira um numero positivo.\n");
        return 1;
    }

    while (numero != 0) {
        invertido = invertido * 10 + numero % 10;
        numero /= 10;
    }

    printf("Numero invertido: %d\n", invertido);

    return 0;
}

