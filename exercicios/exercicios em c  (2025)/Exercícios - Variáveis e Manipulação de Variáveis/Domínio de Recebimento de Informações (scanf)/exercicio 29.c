#include <stdio.h>

int main() {
    float horas_trabalhadas, valor_hora, salario_bruto, salario_liquido;

    printf("Digite o numero de horas trabalhadas: ");
    scanf("%f", &horas_trabalhadas);

    printf("Digite o valor da hora trabalhada: ");
    scanf("%f", &valor_hora);

    salario_bruto = horas_trabalhadas * valor_hora;

    salario_liquido = salario_bruto - (salario_bruto * 0.10);

    printf("O salario bruto e: %.2f\n", salario_bruto);
    printf("O salario liquido, considerando 10%% de impostos, e: %.2f\n", salario_liquido);

    return 0;
}

