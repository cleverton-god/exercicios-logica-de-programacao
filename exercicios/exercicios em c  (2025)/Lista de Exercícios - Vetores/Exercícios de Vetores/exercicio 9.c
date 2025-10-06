#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numeros[10];
	int numero;
	int encontrado = 0;

    srand(time(NULL));
    
    for (int i = 0; i < 10; i++) {
        numeros[i] = rand() % 100;
        printf("%d ", numeros[i]);
    }

    printf("\nDigite um numero para buscar: ");
    scanf("%d", &numero);
    
    for (int i = 0; i < 10; i++) {
        if (numeros[i] == numero) {
            printf("Numero encontrado na posicao %d\n", i);
            encontrado = 1;
            break;
        }
    }
    
    if (!encontrado) {
        printf("Numero nao encontrado\n");
    }

    return 0;
}

