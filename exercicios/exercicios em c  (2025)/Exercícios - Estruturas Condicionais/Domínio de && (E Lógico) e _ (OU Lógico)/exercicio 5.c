#include <stdio.h>

int main() {
    float salario, imposto = 0;

    printf("Digite o salario do funcionario: ");
    scanf("%f", &salario);

    if (salario > 4664.68) {
        imposto = salario * 0.275;
    } else if (salario > 3751.05) {
        imposto = salario * 0.225;
    } else if (salario > 2826.65) {
        imposto = salario * 0.15;
    } else if (salario > 1903.98) {
        imposto = salario * 0.075;
    }

    printf("Imposto devido: R$ %.2f\n", imposto);

    return 0;
}

