#include <stdio.h>

int main() {
    int matriz[4][4] = {
        {10, 20, 30, 40},
        {50, 60, 70, 80},
        {90, 100, 110, 120},
        {130, 140, 150, 160}
    };
    int num, encontrado = 0;

    printf("Digite um numero para buscar: ");
    scanf("%d", &num);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (matriz[i][j] == num) {
                printf("Numero encontrado na posicao [%d][%d]\n", i, j);
                encontrado = 1;
            }
        }
    }

    if (!encontrado) {
        printf("Numero nao encontrado na matriz.\n");
    }

    return 0;
}
