#include <stdio.h>

int main() {
    float valor_original,percentual_desconto,valor_final;

    printf("Digite o valor do produto: ");
    scanf("%f",&valor_original);

    printf("Digite o percentual de desconto: ");
    scanf("%f",&percentual_desconto);

    valor_final=valor_original-(valor_original*percentual_desconto/100);

    printf("O valor final com desconto e: %.2f\n",valor_final);

    return 0;
}

