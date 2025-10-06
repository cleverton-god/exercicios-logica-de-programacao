#include <stdio.h>

int main() {
    int tipo_cartao;
    float valor_compra, valor_final;
    printf("Digite o tipo de cartao (1 - Normal, 2 - Universitario, 3 - Premium): ");
    scanf("%d", &tipo_cartao);
    printf("Digite o valor da compra: ");
    scanf("%f", &valor_compra);
    
    switch (tipo_cartao) {
        case 1: valor_final = valor_compra * 0.95; break; // 5% de desconto
        case 2: valor_final = valor_compra * 0.90; break; // 10% de desconto
        case 3: valor_final = valor_compra * 0.85; break; // 15% de desconto
        default: printf("Tipo de cartao invalido\n"); return 0;
    }
    
    printf("Valor final: %.2f\n", valor_final);

    return 0;
}

