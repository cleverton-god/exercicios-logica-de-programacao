#include <stdio.h>

float calcularMedia(float a, float b) {
    return (a + b) / 2;
}

int main() {
    float x, y;
    printf("Digite dois numeros: ");
    scanf("%f %f", &x, &y);
    printf("Media: %.2f\n", calcularMedia(x, y));
    return 0;
}
