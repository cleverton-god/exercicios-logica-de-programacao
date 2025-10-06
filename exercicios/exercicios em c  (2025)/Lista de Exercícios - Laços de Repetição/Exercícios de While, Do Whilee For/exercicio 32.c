#include <stdio.h>

int main() {
    float temperatura;
	float resultado;
    int origem;
	int destino;

    printf("Digite a temperatura: ");
    scanf("%f", &temperatura);

    printf("Escolha a escala de origem:\n1 - Celsius\n2 - Fahrenheit\n3 - Kelvin\n");
    scanf("%d", &origem);

    printf("Escolha a escala de destino:\n1 - Celsius\n2 - Fahrenheit\n3 - Kelvin\n");
    scanf("%d", &destino);

    if (origem == destino) {
        printf("Temperatura convertida: %.2f\n", temperatura);
        return 0;
    }

    if (origem == 1 && destino == 2) resultado = temperatura * 9 / 5 + 32;
    else if (origem == 1 && destino == 3) resultado = temperatura + 273.15;
    else if (origem == 2 && destino == 1) resultado = (temperatura - 32) * 5 / 9;
    else if (origem == 2 && destino == 3) resultado = (temperatura + 459.67) * 5 / 9;
    else if (origem == 3 && destino == 1) resultado = temperatura - 273.15;
    else if (origem == 3 && destino == 2) resultado = temperatura * 9 / 5 - 459.67;
    else {
        printf("Opcao invalida!\n");
        return 1;
    }

    printf("Temperatura convertida: %.2f\n", resultado);
    return 0;
}

