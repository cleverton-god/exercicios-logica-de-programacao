#include <stdio.h>

int main() {
    int matriz[4][4] = {
        {1,2,3,4},
        {2,5,6,7},
        {3,6,8,9},
        {4,7,9,10}
    };
    int simetrica = 1;

    for (int i = 0; i < 4 && simetrica; i++)
        for (int j = 0; j < 4; j++)
            if (matriz[i][j] != matriz[j][i]) {
                simetrica = 0;
                break;
            }

    if (simetrica)
        printf("A matriz e simetrica.\n");
    else
        printf("A matriz nao e simetrica.\n");

    return 0;
}
