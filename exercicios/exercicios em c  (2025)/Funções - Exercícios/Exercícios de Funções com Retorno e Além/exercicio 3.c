#include <stdio.h>

int ehPositivo(int n) {
    return n > 0;
}

int main() {
    int num;
    printf("Digite um numero: ");
    scanf("%d", &num);
    if (ehPositivo(num))
        printf("Numero positivo.\n");
    else
        printf("Numero negativo ou zero.\n");
    return 0;
}
