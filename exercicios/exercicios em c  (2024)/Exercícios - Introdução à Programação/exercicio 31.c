#include <stdio.h>

int main() {
    float salarioBase;
    
    printf("Digite o salario base do funcionario: ");
    scanf("%f", &salarioBase);
    
    float salarioFinal = salarioBase + (salarioBase * 0.05) - (salarioBase * 0.07);
    printf("O salario final e: %.2f\n", salarioFinal);
    
    return 0;
}

