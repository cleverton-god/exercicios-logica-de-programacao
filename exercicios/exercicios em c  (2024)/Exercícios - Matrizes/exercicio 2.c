#include <stdio.h>

int main() {
   
    int matriz[4][4];
    int soma = 0;

   
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            matriz[i][j] = i + j; 
            soma += matriz[i][j]; 
        }
    }

    printf("Soma dos elementos: %d\n", soma);
    return 0;
}
