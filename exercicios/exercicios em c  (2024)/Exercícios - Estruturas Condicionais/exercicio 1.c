#include <stdio.h>

int main() {
    float numero;
    printf("Digite um numero: ");
    scanf("%f", &numero);
    
    if (numero > 0) {
        printf("O numero %.2f e positivo.\n", numero);
    } else if (numero < 0) {
        printf("O numero %.2f e negativo.\n", numero);
    } 

    return 0;
}

