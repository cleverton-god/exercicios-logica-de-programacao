#include <stdio.h>

int ehPrimo(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return 0;
    return 1;
}

int main() {
    int matriz[3][3] = {
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12}
    };

    printf("Numeros primos na matriz:\n");
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (ehPrimo(matriz[i][j]))
                printf("%d ", matriz[i][j]);

    return 0;
}
