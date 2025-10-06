#include <stdio.h>

int main() {
    int matriz[4][4] = {
        {10, 20, 30, 40},
        {5, 15, 25, 35},
        {2, 4, 6, 8},
        {1, 3, 5, 7}
    };
    int soma = 0;

    for (int j = 0; j < 4; j++)
        soma += matriz[0][j];

    printf("Soma da primeira linha: %d\n", soma);

    return 0;
}
