#include <stdio.h>

int main() {
    float lado1, lado2, lado3;
    printf("Digite os tres lados do triangulo: ");
    scanf("%f %f %f", &lado1, &lado2, &lado3);
    
    if (lado1 == lado2 && lado2 == lado3) {
        printf("Triangulo equilatero\n");
    } else if (lado1 == lado2 || lado1 == lado3 || lado2 == lado3) {
        printf("Triangulo isosceles\n");
    } else {
        printf("Triangulo escaleno\n");
    }

    return 0;
}

