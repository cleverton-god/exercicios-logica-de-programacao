#include <stdio.h>

int main() {
    double capital, taxa, montante;
    int meses, contador = 0;

    printf("Digite o valor inicial do investimento: ");
    scanf("%lf", &capital);

    printf("Digite a taxa de juros mensal (em %%): ");
    scanf("%lf", &taxa);

    printf("Digite o numero de meses: ");
    scanf("%d", &meses);

    montante = capital;

    while (contador < meses) {
        montante = montante * (1 + (taxa / 100));  
        contador++; 
    }

    printf("Valor final do investimento: R$%.2lf\n", montante);
    return 0;
}

