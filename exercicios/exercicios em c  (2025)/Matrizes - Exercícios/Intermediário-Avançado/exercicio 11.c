#include <stdio.h>

int main() {
    int matriz[4][4], valor = 1;

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            matriz[i][j] = valor++;

    printf("Matriz com numeros crescentes:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            printf("%3d ", matriz[i][j]);
        printf("\n");
    }

    return 0;
}
