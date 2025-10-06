#include <stdio.h>

int main() {
    int horasTrabalhadas;
    float valorHora;
    
    printf("Digite o numero de horas trabalhadas: ");
    scanf("%d", &horasTrabalhadas);
    printf("Digite o valor da hora: ");
    scanf("%f", &valorHora);
    
    float salarioBruto = horasTrabalhadas * valorHora;
    float salarioLiquido = salarioBruto - (salarioBruto * 0.10);
    
    printf("Salario bruto: %.2f, Salario liquido: %.2f\n", salarioBruto, salarioLiquido);
    
    return 0;
}

