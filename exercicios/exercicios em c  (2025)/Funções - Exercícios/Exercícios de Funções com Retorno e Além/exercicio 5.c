#include <stdio.h>

int menorValor(int v[], int tam) {
    int menor = v[0];
    for (int i = 1; i < tam; i++)
        if (v[i] < menor)
            menor = v[i];
    return menor;
}

int main() {
    int v[5];
    printf("Digite 5 numeros: ");
    for (int i = 0; i < 5; i++) scanf("%d", &v[i]);
    printf("Menor valor: %d\n", menorValor(v, 5));
    return 0;
}
