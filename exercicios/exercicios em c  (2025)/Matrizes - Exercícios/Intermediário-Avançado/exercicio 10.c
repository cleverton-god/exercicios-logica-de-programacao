#include <stdio.h>

int main() {
    int matriz[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    }, escalar;

    printf("Digite um numero inteiro para multiplicar a matriz: ");
    scanf("%d", &escalar);

    printf("Matriz multiplicada por %d:\n", escalar);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            printf("%3d ", matriz[i][j] * escalar);
        printf("\n");
    }

    return 0;
}
