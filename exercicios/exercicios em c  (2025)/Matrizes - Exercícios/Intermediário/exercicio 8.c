#include <stdio.h>

int main() {
    int matriz[5][5] = {
        {10, 22, 35, 40, 5},
        {60, 14, 78, 89, 33},
        {21, 50, 63, 71, 18},
        {84, 99, 12, 8, 46},
        {70, 65, 27, 3, 100}
    };
    int maior = matriz[0][0], menor = matriz[0][0];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matriz[i][j] > maior)
                maior = matriz[i][j];
            if (matriz[i][j] < menor)
                menor = matriz[i][j];
        }
    }

    printf("Maior elemento: %d\n", maior);
    printf("Menor elemento: %d\n", menor);

    return 0;
}
