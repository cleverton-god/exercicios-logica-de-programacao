#include <stdio.h>

int quadrado(int numero) {
    return numero * numero;
}

int main() {
    int valor;
    printf("Digite um numero: ");
    scanf("%d", &valor);
    printf("Quadrado: %d\n", quadrado(valor));
    return 0;
}
