#include <stdio.h>

int main() {
    float valor, valor_final;
    int forma_pagamento;

    printf("Digite o valor da compra: ");
    scanf("%f", &valor);
    printf("Escolha a forma de pagamento (1-à vista, 2-à prazo 30 dias, 3-à prazo 60 dias, 4-à prazo 90 dias): ");
    scanf("%d", &forma_pagamento);

    if (forma_pagamento == 1) {
        valor_final = valor * 0.90; 
    } else if (forma_pagamento == 2) {
        valor_final = valor * 0.95; 
    } else if (forma_pagamento == 3) {
        valor_final = valor; 
    } else if (forma_pagamento == 4) {
        valor_final = valor * 1.05; 
    } else {
        printf("Forma de pagamento invalida.\n");
        return 1;
    }

    printf("Valor final: R$ %.2f\n", valor_final);
    return 0;
}

