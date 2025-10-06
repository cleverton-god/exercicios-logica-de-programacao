#include <stdio.h>

float mediaNotas(float notas[], int n) {
    float soma = 0;
    for (int i = 0; i < n; i++)
        soma += notas[i];
    return soma / n;
}

int main() {
    float notas[5];
    printf("Digite 5 notas: ");
    for (int i = 0; i < 5; i++) scanf("%f", &notas[i]);
    printf("Media: %.2f\n", mediaNotas(notas, 5));
    return 0;
}
