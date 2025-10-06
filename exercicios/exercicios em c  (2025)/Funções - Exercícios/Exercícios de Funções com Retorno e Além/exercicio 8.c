#include <stdio.h>

float celsiusParaFahrenheit(float c) {
    return (c * 1.8) + 32;
}

float fahrenheitParaCelsius(float f) {
    return (f - 32) / 1.8;
}

int main() {
    int opcao;
    float temp;
    printf("1 - Celsius para Fahrenheit\n2 - Fahrenheit para Celsius\nEscolha: ");
    scanf("%d", &opcao);
    printf("Digite a temperatura: ");
    scanf("%f", &temp);
    if (opcao == 1)
        printf("Resultado: %.2f F\n", celsiusParaFahrenheit(temp));
    else
        printf("Resultado: %.2f C\n", fahrenheitParaCelsius(temp));
    return 0;
}
