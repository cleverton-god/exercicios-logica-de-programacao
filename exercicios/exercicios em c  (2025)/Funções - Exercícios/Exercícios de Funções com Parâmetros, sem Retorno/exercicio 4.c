#include <stdio.h>

int somaAteN(int n) {
    int soma = 0;
    for (int i = 1; i <= n; i++) {
        soma += i;
    }
    return soma;
}

int main() {
    int n;
    printf("Digite um numero: ");
    scanf("%d", &n);
    printf("Soma de 1 ate %d: %d\n", n, somaAteN(n));
    return 0;
}
