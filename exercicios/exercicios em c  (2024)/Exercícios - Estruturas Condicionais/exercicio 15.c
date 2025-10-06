#include <stdio.h>

int main() {
    float peso, altura, imc;
    printf("Digite o peso (kg) e altura (m): ");
    scanf("%f %f", &peso, &altura);
    
    imc = peso / (altura * altura);
    
    if (imc < 18.5) {
        printf("Abaixo do peso\n");
    } else if (imc < 24.9) {
        printf("Peso normal\n");
    } else if (imc < 29.9) {
        printf("Sobrepeso\n");
    } else {
        printf("Obeso\n");
    }

    return 0;
}

