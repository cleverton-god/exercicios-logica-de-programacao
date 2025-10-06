#include <stdio.h>

int main() {
    float produto1, produto2, produto3;

    printf("Digite o valor do primeiro produto: ");
    scanf("%f", &produto1);
    
    printf("Digite o valor do segundo produto: ");
    scanf("%f", &produto2);
    
    printf("Digite o valor do terceiro produto: ");
    scanf("%f", &produto3);

    if (produto1 <= produto2 && produto1 <= produto3) {
        printf("O produto mais barato custa: %.2f\n", produto1);
    } else if (produto2 <= produto1 && produto2 <= produto3) {
        printf("O produto mais barato custa: %.2f\n", produto2);
    } else {
        printf("O produto mais barato custa: %.2f\n", produto3);
    }

    return 0;
}

