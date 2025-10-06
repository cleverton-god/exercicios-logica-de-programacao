#include <stdio.h>

int main() {
    float produto1, produto2, produto3;

    printf("Digite o valor do primeiro produto: R$ ");
    scanf("%f", &produto1);
    
    printf("Digite o valor do segundo produto: R$ ");
    scanf("%f", &produto2);
    
    printf("Digite o valor do terceiro produto: R$ ");
    scanf("%f", &produto3);

    
    if (produto1 < produto2 && produto1 < produto3) {
        printf("O primeiro produto e o mais barato. R$ %.2f\n", produto1);
    } else if (produto2 < produto1 && produto2 < produto3) {
        printf("O segundo produto e o mais barato. R$ %.2f\n", produto2);
    } else {
        printf("O terceiro produto e o mais barato. R$ %.2f\n", produto3);
    }

    return 0;
}

