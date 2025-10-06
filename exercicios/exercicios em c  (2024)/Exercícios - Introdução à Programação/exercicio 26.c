#include <stdio.h>

int main() {
    float base, altura;
    
    printf("Digite a base do triangulo: ");
    scanf("%f", &base);
    printf("Digite a altura do triangulo: ");
    scanf("%f", &altura);
    
    float area = (base * altura) / 2;
    printf("A area do triangulo e: %.2f\n", area);
    
    return 0;
}

