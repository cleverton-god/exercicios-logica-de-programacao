#include <stdio.h>

int main() {
    int valor, notas50 = 0, notas20 = 0, notas10 = 0, notas5 = 0;

    printf("Digite o valor do saque: ");
    scanf("%d", &valor);

    if (valor <= 0) {
        printf("Valor invalido!\n");
        return 1;
    }

    while (valor >= 50) {
        notas50++;
        valor -= 50;
    }

    while (valor >= 20) {
        notas20++;
        valor -= 20;
    }

    while (valor >= 10) {
        notas10++;
        valor -= 10;
    }

    while (valor >= 5) {
        notas5++;
        valor -= 5;
    }

    printf("Notas necessarias:\n");
    if (notas50) printf("%d nota(s) de R$50\n", notas50);
    if (notas20) printf("%d nota(s) de R$20\n", notas20);
    if (notas10) printf("%d nota(s) de R$10\n", notas10);
    if (notas5) printf("%d nota(s) de R$5\n", notas5);
    if (valor) printf("Valor restante nao pode ser sacado: R$%d\n", valor);

    return 0;
}

