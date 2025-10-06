#include <stdio.h>

int ehPositivo(int n) {
    return n > 0;
}

int main() {
    int n;
    printf("Digite um numero: ");
    scanf("%d", &n);
    if (ehPositivo(n))
        printf("Numero positivo\n");
    else
        printf("Numero negativo ou zero\n");
    return 0;
}
