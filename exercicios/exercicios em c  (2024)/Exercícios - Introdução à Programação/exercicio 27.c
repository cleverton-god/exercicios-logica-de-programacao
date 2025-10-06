#include <stdio.h>

int main() {
    float fahrenheit;
    
    printf("Digite a temperatura em Fahrenheit: ");
    scanf("%f", &fahrenheit);
    
    float celsius = (fahrenheit - 32) * 5 / 9;
    printf("A temperatura em Celsius e: %.2f\n", celsius);
    
    return 0;
}

