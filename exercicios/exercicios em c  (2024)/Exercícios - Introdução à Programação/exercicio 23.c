#include <stdio.h>

int main() {
    float valorCompra;
    int parcelas;
    
    printf("Digite o valor da compra: ");
    scanf("%f", &valorCompra);
    printf("Digite a quantidade de parcelas: ");
    scanf("%d", &parcelas);
    
    float valorParcela = valorCompra / parcelas;
    printf("O valor de cada parcela e: %.2f\n", valorParcela);
    
    return 0;
}

