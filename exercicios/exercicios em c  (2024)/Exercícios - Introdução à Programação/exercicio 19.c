#include <stdio.h>

int main() {
    float raio;  
    float pi = 3.14; 

    printf("Digite o raio do circulo: ");
    scanf("%f", &raio);  

    float area = pi * raio * raio;  

    printf("A area do circulo e: %.2f\n", area);  

    return 0;
}

