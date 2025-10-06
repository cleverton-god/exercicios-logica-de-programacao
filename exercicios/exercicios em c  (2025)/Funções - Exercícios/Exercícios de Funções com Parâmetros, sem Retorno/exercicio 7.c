#include <stdio.h>

int encontrarMaior(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int num1, num2;
    printf("Digite dois numeros: ");
    scanf("%d %d", &num1, &num2);
    printf("Maior numero: %d\n", encontrarMaior(num1, num2));
    return 0;
}
