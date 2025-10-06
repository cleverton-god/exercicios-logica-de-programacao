#include <stdio.h>

int main() {
    int matriz[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    int transposta[4][3];

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 4; j++)
            transposta[j][i] = matriz[i][j];

    printf("Matriz original:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++)
            printf("%3d ", matriz[i][j]);
        printf("\n");
    }

    printf("\nMatriz transposta:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++)
            printf("%3d ", transposta[i][j]);
        printf("\n");
    }

    return 0;
}
