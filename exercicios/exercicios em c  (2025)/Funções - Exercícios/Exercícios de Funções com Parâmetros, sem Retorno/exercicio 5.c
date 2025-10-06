#include <stdio.h>

void verificarParImpar(int numero) {
    if (numero % 2 == 0) {
        printf("O numero e par.\n");
    } else {
        printf("O numero e impar.\n");
    }
}

int main() {
    int num;
    printf("Digite um numero: ");
    scanf("%d", &num);
    verificarParImpar(num);
    return 0;
}
