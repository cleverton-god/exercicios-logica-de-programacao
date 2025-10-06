#include <stdio.h>

int menorValor(int v[], int n) {
    int menor = v[0];
    for (int i = 1; i < n; i++)
        if (v[i] < menor) menor = v[i];
    return menor;
}

int main() {
    int v[100], n;
    printf("Quantidade de elementos: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &v[i]);
    }
    printf("Menor valor: %d\n", menorValor(v, n));
    return 0;
}
