#include <stdio.h>

int main() {
    float salario, novoSalario;

    printf("Digite o salario do funcionário: ");
    scanf("%f", &salario);

    novoSalario=salario+(salario*0.15);

    printf("O novo salario com aumento de 15%% é: R$ %.2f\n",novoSalario);

    return 0;
}

