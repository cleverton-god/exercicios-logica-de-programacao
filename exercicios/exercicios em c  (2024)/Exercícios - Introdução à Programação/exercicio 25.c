#include <stdio.h>

int main() {
    float peso, altura;
    
    printf("Digite o peso em kg: ");
    scanf("%f", &peso);
    printf("Digite a altura em metros: ");
    scanf("%f", &altura);
    
    float imc = peso / (altura * altura);
    printf("O IMC e: %.2f\n", imc);
    
    return 0;
}

