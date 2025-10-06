#include <stdio.h>

#define TAM 5

int existeNoVetor(int vetor[], int tamanho, int num) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == num) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int vetor1[TAM] = {1, 3, 5, 7, 9};
    int vetor2[TAM] = {2, 3, 6, 7, 10};

    printf("Intersecao dos vetores: ");
    for (int i = 0; i < TAM; i++) {
        if (existeNoVetor(vetor2, TAM, vetor1[i])) {
            printf("%d ", vetor1[i]);
        }
    }
    printf("\n");

    return 0;
}

