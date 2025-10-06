#include <stdio.h>

int main() {
    int matriz[2][2] = {
        {4, 2},
        {1, 3}
    };

    int determinante = matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];
    printf("Determinante: %d\n", determinante);

    return 0;
}
