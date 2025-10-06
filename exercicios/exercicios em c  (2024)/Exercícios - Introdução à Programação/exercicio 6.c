#include <stdio.h>

int main() {
    int numero;  

    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);  

    int dobro = numero * 2; 

    printf("O dobro de %d e %d.\n", numero, dobro);  

    return 0;
}

