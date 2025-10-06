#include <stdio.h>

int main() {
    float litros, valor;
    char tipo_combustivel;
    printf("Digite o numero de litros vendidos: ");
    scanf("%f", &litros);
    printf("Digite o tipo de combustivel (a - alcool, g - gasolina): ");
    scanf(" %c", &tipo_combustivel);
    
    if (tipo_combustivel == 'a') {
        if (litros <= 20) {
            valor = litros * 1.90 * 0.97; 
        } else {
            valor = litros * 1.90 * 0.95; 
        }
    } else if (tipo_combustivel == 'g') {
        if (litros <= 20) {
            valor = litros * 2.50 * 0.96; 
        } else {
            valor = litros * 2.50 * 0.94; 
        }
    } else {
        printf("Tipo de combustivel invalido\n");
        return 0;
    }

    printf("Valor a ser pago: %.2f\n", valor);

    return 0;
}

