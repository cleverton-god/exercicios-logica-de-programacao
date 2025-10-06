#include <stdio.h>

int main() {
    float raio, altura;
    const float pi = 3.14159;
    
    printf("Digite o raio do cilindro: ");
    scanf("%f", &raio);
    printf("Digite a altura do cilindro: ");
    scanf("%f", &altura);
    
    float volume = pi * raio * raio * altura;
    printf("O volume do cilindro e: %.2f\n", volume);
    
    return 0;
}

