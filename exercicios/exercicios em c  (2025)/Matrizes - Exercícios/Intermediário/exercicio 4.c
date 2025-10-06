#include <stdio.h>

int main() {
    int matriz[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 1, 2, 3},
        {4, 5, 6, 7}
    };

    // Soma por linha
    for (int i = 0; i < 4; i++) {
        int somaLinha = 0;
        for (int j = 0; j < 4; j++) {
            somaLinha += matriz[i][j];
        }
        printf("Soma da linha %d: %d\n", i, somaLinha);
    }

    // Soma por coluna
    for (int j = 0; j < 4; j++) {
        int somaColuna = 0;
        for (int i = 0; i < 4; i++) {
            somaColuna += matriz[i][j];
        }
        printf("Soma da coluna %d: %d\n", j, somaColuna);
    }

    return 0;
}
