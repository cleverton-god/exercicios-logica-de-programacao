#include <stdio.h>

void ordenarCrescente(int v[], int tam) {
    int i, j, aux;
    for (i = 0; i < tam - 1; i++)
        for (j = i + 1; j < tam; j++)
            if (v[i] > v[j]) {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
}

int main() {
    int v[5];
    printf("Digite 5 numeros: ");
    for (int i = 0; i < 5; i++) scanf("%d", &v[i]);
    ordenarCrescente(v, 5);
    printf("Ordenado: ");
    for (int i = 0; i < 5; i++) printf("%d ", v[i]);
    printf("\n");
    return 0;
}
