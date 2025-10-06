#include <stdio.h>

int main() {
    int matriz[5][5], invertida[5][5];

    int valor = 1;
    for (int i = 0; i < 5; i++)  // preencher com valores simples
        for (int j = 0; j < 5; j++)
            matriz[i][j] = valor++;

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            invertida[i][j] = matriz[4 - i][j];

    printf("Matriz original:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            printf("%3d ", matriz[i][j]);
        printf("\n");
    }

    printf("\nMatriz com linhas invertidas:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            printf("%3d ", invertida[i][j]);
        printf("\n");
    }

    return 0;
}
