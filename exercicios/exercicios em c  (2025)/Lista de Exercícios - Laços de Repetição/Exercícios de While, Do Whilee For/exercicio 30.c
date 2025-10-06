#include <stdio.h>

int main() {
    int inicio;
	int fim;

    printf("Digite o primeiro numero: ");
    scanf("%d", &inicio);
    printf("Digite o segundo numero: ");
    scanf("%d", &fim);

    if (inicio > fim) {
        int temp = inicio;
        inicio = fim;
        fim = temp;
    }

    printf("Numeros no intervalo: ");
    for (int i = inicio; i <= fim; i++) {
        printf("%d ", i);
    }
    printf("\n");

    return 0;
}

