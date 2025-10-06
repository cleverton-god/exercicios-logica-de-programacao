#include <stdio.h>

int main() {
    int matriz[6][6] = {0};
    matriz[1][2] = 5;
    matriz[3][4] = 7;
    matriz[5][0] = 3;
    int contador = 0;

    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
            if (matriz[i][j] != 0)
                contador++;

    printf("Quantidade de elementos diferentes de zero: %d\n", contador);

    return 0;
}
