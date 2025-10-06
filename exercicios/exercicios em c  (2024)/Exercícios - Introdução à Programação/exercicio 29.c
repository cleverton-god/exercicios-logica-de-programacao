#include <stdio.h>

int main() {
    float valorOriginal, percentualDesconto;
    
    printf("Digite o valor do produto: ");
    scanf("%f", &valorOriginal);
    printf("Digite o percentual de desconto: ");
    scanf("%f", &percentualDesconto);
    
    float valorFinal = valorOriginal - (valorOriginal * percentualDesconto / 100);
    printf("O valor final com desconto e: %.2f\n", valorFinal);
    
    return 0;
}

