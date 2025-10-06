#include <stdio.h>

int main() {
    int numero, negativos = 0;

    for (int i = 0; i < 5; i++) {
        printf("Digite um numero: ");
        scanf("%d", &numero);
        
        if (numero < 0) {
            negativos++;
        }
    }

    printf("Quantidade de numeros negativos: %d\n", negativos);
    return 0;
}

