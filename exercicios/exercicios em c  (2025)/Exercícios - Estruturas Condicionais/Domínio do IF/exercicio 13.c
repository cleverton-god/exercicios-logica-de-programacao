#include <stdio.h>

int main() {
    int tipo_cartao;
    float valor_compra, valor_com_desconto;

    printf("Informe o tipo do cartao de credito 1 - Normal, 2 - Universitario, 3 - Premium: ");
    scanf("%d", &tipo_cartao);
    
    printf("Informe o valor da compra: ");
    scanf("%f", &valor_compra);

    if (tipo_cartao == 1) {
        valor_com_desconto = valor_compra * 0.95;
    } else if (tipo_cartao == 2) {
        valor_com_desconto = valor_compra * 0.90;
    } else if (tipo_cartao == 3) {
        valor_com_desconto = valor_compra * 0.85;
    } else {
        printf("Tipo de cartao invalido!\n");
        return 1;
    }

    printf("O valor da compra com desconto e: R$ %.2f\n", valor_com_desconto);

    return 0;
}

