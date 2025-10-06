#include <stdio.h>

int somar(int a, int b) {
    return a + b;
}

int main() {
    int x, y;
    printf("Digite dois numeros: ");
    scanf("%d %d", &x, &y);
    printf("Soma: %d\n", somar(x, y));
    return 0;
}
