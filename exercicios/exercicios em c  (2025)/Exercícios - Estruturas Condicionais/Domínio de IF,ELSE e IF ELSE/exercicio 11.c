#include <stdio.h>

int main() {
   
    int litros;
    char combustivel;
    float preco_alcool = 1.90;
    float preco_gasolina = 2.50;
    float valor_total;

    
    printf("Digite o tipo de combustivel A - Alcool / G - Gasolina): ");
    scanf(" %c", &combustivel); 
    
    printf("Digite a quantidade de litros vendidos: ");
    scanf("%d", &litros);

    
    if (combustivel == 'A' || combustivel == 'a') {
        if (litros <= 20) {
            valor_total = litros * preco_alcool * 0.97; 
        } else {
            valor_total = litros * preco_alcool * 0.95; 
        }
    } else if (combustivel == 'G' || combustivel == 'g') {
        if (litros <= 20) {
            valor_total = litros * preco_gasolina * 0.96; 
        } else {
            valor_total = litros * preco_gasolina * 0.94; 
        }
    } else {
        printf("Combustivel invalido!\n");
        return 1; 
    }

    
    printf("O valor a ser pago e: R$ %.2f\n", valor_total);

    return 0;
}


