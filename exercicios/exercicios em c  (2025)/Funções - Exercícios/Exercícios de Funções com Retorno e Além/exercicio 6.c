#include <stdio.h>

int somarDigitos(int n) {
    if (n == 0) return 0;
    return (n % 10) + somarDigitos(n / 10);
}

int main() {
    int n;
    printf("Digite um numero: ");
    scanf("%d", &n);
    printf("Soma dos digitos: %d\n", somarDigitos(n));
    return 0;
}
