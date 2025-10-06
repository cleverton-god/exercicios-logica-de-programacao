#include <stdio.h>

#define TAM1 5
#define TAM2 5

int existeNoVetor(int vetor[], int tamanho, int num) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == num) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int vetor1[TAM1] = {1, 3, 5, 7, 9};
    int vetor2[TAM2] = {2, 3, 6, 7, 10};
    int uniao[TAM1 + TAM2];
    int tamanho = 0;

    for (int i = 0; i < TAM1; i++) {
        uniao[tamanho++] = vetor1[i];
    }

    for (int i = 0; i < TAM2; i++) {
        if (!existeNoVetor(uniao, tamanho, vetor2[i])) {
            uniao[tamanho++] = vetor2[i];
        }
    }

    printf("Uniao dos vetores: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", uniao[i]);
    }
    printf("\n");

    return 0;
}

