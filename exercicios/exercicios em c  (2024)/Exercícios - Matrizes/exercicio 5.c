#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	
    int matriz[6][6];
    srand(time(0)); 

    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++) {
            matriz[i][j] = rand() % 100; 
        }
    }

    int numero, encontrado = 0;
    printf("Digite um numero para buscar: ");
    scanf("%d", &numero);

    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++) {
            if(matriz[i][j] == numero) {
                printf("Encontrado na posicao [%d][%d]\n", i, j);
                encontrado = 1;
            }
        }
    }

    if(!encontrado) {
        printf("Numero nao encontrado.\n");
    }

    return 0;
}
