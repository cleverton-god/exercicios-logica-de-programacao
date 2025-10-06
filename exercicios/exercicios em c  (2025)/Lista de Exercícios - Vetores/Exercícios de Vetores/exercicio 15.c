#include <stdio.h>

int main() {
    int numeros[10] = {2, 5, 8, 10, 15, 20, 25, 30, 35, 40};
    int inicio, fim, soma = 0;

    printf("Digite o indice inicial e final da faixa: ");
    scanf("%d %d", &inicio, &fim);

    if (inicio < 0 || fim >= 10 || inicio > fim) {
        printf("Faixa invalida!\n");
        return 1;
    }

    for (int i = inicio; i <= fim; i++) {
        soma += numeros[i];
    }

    printf("Soma dos elementos na faixa: %d\n", soma);

    return 0;
}

