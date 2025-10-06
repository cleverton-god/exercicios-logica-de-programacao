#include <stdio.h>

int main() {
    float produto1, produto2, produto3;

    printf("Digite o valor do primeiro produto: ");
    scanf("%f", &produto1);
    printf("Digite o valor do segundo produto: ");
    scanf("%f", &produto2);
    printf("Digite o valor do terceiro produto: ");
    scanf("%f", &produto3);

    float mais_barato = produto1;

    if (produto2 < mais_barato) {
        mais_barato = produto2;
    }
    if (produto3 < mais_barato) {
        mais_barato = produto3;
    }

    printf("O produto mais barato custa: R$ %.2f\n", mais_barato);
    return 0;
}

