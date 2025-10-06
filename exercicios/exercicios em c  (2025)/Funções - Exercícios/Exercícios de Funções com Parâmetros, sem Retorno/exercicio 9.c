#include <stdio.h>

int calcularFatorial(int n) {
    int fat = 1;
    for (int i = 2; i <= n; i++) {
        fat *= i;
    }
    return fat;
}

int main() {
    int num;
    printf("Digite um numero nao negativo: ");
    scanf("%d", &num);
    if (num < 0) {
        printf("Numero invalido.\n");
    } else {
        printf("Fatorial de %d: %d\n", num, calcularFatorial(num));
    }
    return 0;
}
