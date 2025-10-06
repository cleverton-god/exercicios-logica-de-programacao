#include <stdio.h>

int modulo(int n) {
    return n < 0 ? -n : n;
}

int main() {
    int n;
    printf("Digite um numero: ");
    scanf("%d", &n);
    printf("Modulo: %d\n", modulo(n));
    return 0;
}
