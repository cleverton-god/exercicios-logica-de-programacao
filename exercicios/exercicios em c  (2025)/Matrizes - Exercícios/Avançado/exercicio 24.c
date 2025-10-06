#include <stdio.h>

int main() {
    int matriz[4][4] = {
        {4, 8, 2, 6},
        {5, 3, 7, 1},
        {9, 0, 4, 2},
        {6, 1, 8, 5}
    };

    for (int j = 0; j < 4; j++) {
        float soma = 0;
        for (int i = 0; i < 4; i++)
            soma += matriz[i][j];
        printf("Media da coluna %d: %.2f\n", j + 1, soma / 4);
    }

    return 0;
}
