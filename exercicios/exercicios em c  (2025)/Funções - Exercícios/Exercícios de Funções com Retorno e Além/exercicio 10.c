#include <stdio.h>

int ehPrimo(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return 0;
    return 1;
}

int main() {
    int n;
    printf("Digite um numero: ");
    scanf("%d", &n);
    if (ehPrimo(n))
        printf("Numero primo.\n");
    else
        printf("Nao e primo.\n");
    return 0;
}
