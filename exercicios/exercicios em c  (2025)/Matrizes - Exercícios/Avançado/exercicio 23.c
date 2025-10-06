#include <stdio.h>

int main() {
    int matriz[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    int rotacionada[3][3];

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            rotacionada[j][2 - i] = matriz[i][j];

    printf("Matriz rotacionada 90 graus:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            printf("%3d ", rotacionada[i][j]);
        printf("\n");
    }

    return 0;
}
