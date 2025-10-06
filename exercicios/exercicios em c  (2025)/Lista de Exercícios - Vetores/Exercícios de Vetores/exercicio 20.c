#include <stdio.h>

#define TAM 10

int existeNoVetor(int vetor[], int tamanho, int num) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == num) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int vetor[TAM] = {1, 3, 5, 3, 7, 9, 5, 7, 2, 10};
    int unicos[TAM] ;
    int tamanho = 0;

    for (int i = 0; i < TAM; i++) {
        if (!existeNoVetor(unicos, tamanho, vetor[i])) {
            unicos[tamanho++] = vetor[i];
        }
    }

    printf("Vetor sem duplicatas: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", unicos[i]);
    }
    printf("\n");

    return 0;
}


