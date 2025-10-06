#include <stdio.h>
#include <stdbool.h>

bool ehPrimo(int numero) {
    if (numero <= 1) return false;
    for (int i = 2; i < numero; i++) {
        if (numero % i == 0) return false;
    }
    return true;
}

int main() {
    int num;
    printf("Digite um numero: ");
    scanf("%d", &num);
    if (ehPrimo(num)) {
        printf("O numero e primo.\n");
    } else {
        printf("O numero nao e primo.\n");
    }
    return 0;
}
