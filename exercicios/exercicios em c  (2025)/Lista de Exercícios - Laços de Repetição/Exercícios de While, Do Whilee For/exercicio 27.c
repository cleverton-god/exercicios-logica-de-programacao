#include <stdio.h>

int ehPrimo(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {
    int quantidade, num = 2, cont = 0;

    printf("Quantos numeros primos deseja gerar? ");
    scanf("%d", &quantidade);

    while (cont < quantidade) {
        if (ehPrimo(num)) {
            printf("%d ", num);
            cont++;
        }
        num++;
    }
    printf("\n");

    return 0;
}

