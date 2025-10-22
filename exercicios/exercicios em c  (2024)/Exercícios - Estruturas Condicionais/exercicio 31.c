#include <stdio.h>

int main() {
    float lado1, lado2, lado3;

    printf("Digite o comprimento dos tres lados do triangulo: ");
    scanf("%f %f %f", &lado1, &lado2, &lado3);

    if (lado1 + lado2 > lado3 && lado1 + lado3 > lado2 && lado2 + lado3 > lado1) {
        if (lado1 == lado2 && lado2 == lado3) {
            printf("Triangulo equilatero.\n");
        } else if (lado1 == lado2 || lado1 == lado3 || lado2 == lado3) {
            printf("Triangulo isosceles.\n");
        } else {
            printf("Triangulo escaleno.\n");
        }
    } else {
        printf("Os lados informados nao formam um triangulo.\n");
    }
    return 0;
}

