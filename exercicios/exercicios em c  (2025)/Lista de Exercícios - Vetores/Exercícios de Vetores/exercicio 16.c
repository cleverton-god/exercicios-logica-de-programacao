#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    int vetor[TAM];
    srand(time(NULL));

    for (int i = 0; i < TAM; i++) {
        int num;
        do {
            num = rand() % 100;
        } while (existeNoVetor(vetor, i, num));

        vetor[i] = num;
    }

    printf("Vetor aleatorio sem repeticao: ");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}

