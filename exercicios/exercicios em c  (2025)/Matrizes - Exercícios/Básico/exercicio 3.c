#include <stdio.h>

int main() {
    float matriz[3][3] = {
        {1.5, 2.0, 3.2},
        {4.5, 5.1, 6.8},
        {7.0, 8.3, 9.9}
    };
    float soma = 0.0;
    int total = 9;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            soma += matriz[i][j];
        }
    }

    float media = soma / total;
    printf("Media dos elementos da matriz 3x3: %.2f\n", media);

    return 0;
}
