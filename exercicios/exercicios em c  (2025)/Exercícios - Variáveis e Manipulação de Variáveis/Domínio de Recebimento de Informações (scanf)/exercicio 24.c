#include <stdio.h>

int main() {
    float valorCompra, valorParcela;
    int parcelas;

   
    printf("Digite o valor da compra: R$ ");
    scanf("%f", &valorCompra);

    
    printf("Digite a quantidade de parcelas: ");
    scanf("%d", &parcelas);

    
    if (parcelas > 0) {
        valorParcela = valorCompra / parcelas;

        printf("O valor de cada parcela sera: R$ %.2f\n", valorParcela);
    } else {
        printf("Número de parcelas invalido. Deve ser maior que 0.\n");
    }

    return 0;
}

