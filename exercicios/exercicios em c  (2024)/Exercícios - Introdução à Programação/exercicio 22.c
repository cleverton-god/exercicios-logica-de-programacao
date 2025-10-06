#include <stdio.h>

int main() {
    float salario;
    printf("Digite o salario do funcionario: ");
    scanf("%f", &salario);
    
    float novoSalario = salario * 1.15;
    printf("O novo salario e: %.2f\n", novoSalario);
    
    return 0;
}

