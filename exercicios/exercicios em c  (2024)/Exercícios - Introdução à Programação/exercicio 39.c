#include <stdio.h>

int main() {
    float raio;
    const float pi = 3.14159;
    
    printf("Digite o raio da esfera: ");
    scanf("%f", &raio);
    
    float volume = (4.0 / 3.0) * pi * (raio * raio * raio);
    printf("O volume da esfera e: %.2f\n", volume);
    
    return 0;
}

