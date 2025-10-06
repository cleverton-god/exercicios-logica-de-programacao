#include <stdio.h>

float converterParaFahrenheit(float celsius) {
    return (celsius * 1.8) + 32;
}

int main() {
    float tempC;
    printf("Digite a temperatura em Celsius: ");
    scanf("%f", &tempC);
    printf("Temperatura em Fahrenheit: %.2f\n", converterParaFahrenheit(tempC));
    return 0;
}
