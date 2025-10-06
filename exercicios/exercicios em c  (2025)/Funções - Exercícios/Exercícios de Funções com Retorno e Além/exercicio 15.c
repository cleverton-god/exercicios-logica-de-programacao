#include <stdio.h>

int maiorValorMatriz(int m[3][3]) {
    int maior = m[0][0];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (m[i][j] > maior)
                maior = m[i][j];
    return maior;
}

int main() {
    int m[3][3];
    printf("Digite os valores da matriz 3x3:\n");
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            scanf("%d", &m[i][j]);
    printf("Maior valor: %d\n", maiorValorMatriz(m));
    return 0;
}
