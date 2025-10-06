#include <stdio.h>

int main() {

    int matriz[4][4];
    int somaLinhas[4] = {0}, somaColunas[4] = {0};

    
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            matriz[i][j] = i + j; 
        }
    }

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            somaLinhas[i] += matriz[i][j];
            somaColunas[j] += matriz[i][j];
        }
    }

    printf("Soma das linhas:\n");
    for(int i = 0; i < 4; i++) {
        printf("Linha %d: %d\n", i, somaLinhas[i]);
    }

    printf("Soma das colunas:\n");
    for(int j = 0; j < 4; j++) {
        printf("Coluna %d: %d\n", j, somaColunas[j]);
    }

    return 0;
}
