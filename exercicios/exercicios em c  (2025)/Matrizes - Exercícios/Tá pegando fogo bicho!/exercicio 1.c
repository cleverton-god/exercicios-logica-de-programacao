#include <stdio.h>
#include <stdbool.h>

#define TAM 3

bool ehQuadradoMagico(int mat[TAM][TAM]) {
    int somaDiagonal1 = 0, somaDiagonal2 = 0;
    int somaLinha, somaColuna;
    int somaMagica;

    // Soma da primeira diagonal
    for (int i = 0; i < TAM; i++) {
        somaDiagonal1 += mat[i][i];
    }

    // Soma da segunda diagonal
    for (int i = 0; i < TAM; i++) {
        somaDiagonal2 += mat[i][TAM - 1 - i];
    }

    // Se as diagonais não têm a mesma soma, não é quadrado mágico
    if (somaDiagonal1 != somaDiagonal2)
        return false;

    somaMagica = somaDiagonal1;

    // Verifica as somas das linhas
    for (int i = 0; i < TAM; i++) {
        somaLinha = 0;
        for (int j = 0; j < TAM; j++) {
            somaLinha += mat[i][j];
        }
        if (somaLinha != somaMagica)
            return false;
    }

    // Verifica as somas das colunas
    for (int j = 0; j < TAM; j++) {
        somaColuna = 0;
        for (int i = 0; i < TAM; i++) {
            somaColuna += mat[i][j];
        }
        if (somaColuna != somaMagica)
            return false;
    }

    return true;
}

int main() {
    int matriz[TAM][TAM];

    printf("Digite os 9 elementos da matriz 3x3:\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    if (ehQuadradoMagico(matriz)) {
        printf("\nA matriz e um quadrado magico!\n");
    } else {
        printf("\nA matriz NAO e um quadrado magico.\n");
    }

    return 0;
}
