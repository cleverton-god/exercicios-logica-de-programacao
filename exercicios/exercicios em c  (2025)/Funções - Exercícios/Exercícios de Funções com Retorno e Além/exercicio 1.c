#include <stdio.h>

int somarDoisNumeros(int a, int b) {
    return a + b;
}

int main() {
    int x, y;
    printf("Digite dois numeros: ");
    scanf("%d %d", &x, &y);
    printf("Soma: %d\n", somarDoisNumeros(x, y));
    return 0;
}
