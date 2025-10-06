#include <stdio.h>

int main() {
    int mes;

    printf("Digite o numero do mes 1 a 12 para descobrir a estacao do ano: ");
    scanf("%d", &mes);

    if (mes == 12 || mes == 1 || mes == 2) {
        printf("estacao: Verao\n");
    } else if (mes == 3 || mes == 4 || mes == 5) {
        printf("estacao: Outono\n");
    } else if (mes == 6 || mes == 7 || mes == 8) {
        printf("estacao: Inverno\n");
    } else if (mes == 9 || mes == 10 || mes == 11) {
        printf("estacao: Primavera\n");
    } else {
        printf("Numero invalido! Digite um valor entre 1 e 12.\n");
    }

    return 0;
}

