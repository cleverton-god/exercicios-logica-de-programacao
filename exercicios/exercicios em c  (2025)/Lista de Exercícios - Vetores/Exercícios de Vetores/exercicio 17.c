#include <stdio.h>

#define TAM 10

int main() {
    int vetor[TAM] = {3, 7, 12, 5, 9, 15, 20, 8, 1, 14};
    int inicio, fim, soma = 0;

    printf("Vetor: ");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    printf("Digite o valor inicial da faixa: ");
    scanf("%d", &inicio);
    printf("Digite o valor final da faixa: ");
    scanf("%d", &fim);

    if (inicio > fim) {
        int temp = inicio;
        inicio = fim;
        fim = temp;
    }

    for (int i = 0; i < TAM; i++) {
        if (vetor[i] >= inicio && vetor[i] <= fim) {
            soma += vetor[i];
        }
    }

    printf("Soma dos elementos na faixa [%d, %d]: %d\n", inicio, fim, soma);

    return 0;
}

