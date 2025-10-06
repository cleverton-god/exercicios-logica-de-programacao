#include <stdio.h>

int main() {
    int matriz[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int somaPrincipal = 0, somaSecundaria = 0;

    for (int i = 0; i < 4; i++) {
        somaPrincipal += matriz[i][i];
        somaSecundaria += matriz[i][3 - i];
    }

    printf("Soma da diagonal principal: %d\n", somaPrincipal);
    printf("Soma da diagonal secundaria: %d\n", somaSecundaria);

    return 0;
}
