#include <stdio.h>

int main() {
    float valor_prestacao, multa, juros;
    int dias_atraso;

    printf("Digite o valor da prestacao: ");
    scanf("%f", &valor_prestacao);

    printf("Digite o numero de dias em atraso: ");
    scanf("%d", &dias_atraso);

    multa = valor_prestacao * 0.02;

    juros = valor_prestacao * (0.001 * dias_atraso);

    printf("A multa e: %.2f\n", multa);
    printf("Os juros sao: %.2f\n", juros);

    return 0;
}

