#include <stdio.h>

int main() {
    float temperaturaCelsius;  

    printf("Digite a temperatura em Celsius: ");
    scanf("%f", &temperaturaCelsius);  

    float temperaturaFahrenheit = temperaturaCelsius * 9.0 / 5.0 + 32;  

    printf("A temperatura em Fahrenheit e: %.2f\n", temperaturaFahrenheit);  

    return 0;
}

