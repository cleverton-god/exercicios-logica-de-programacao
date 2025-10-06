#include <stdio.h>

int main() {
    float largura, comprimento, preco_metro_quadrado, area, preco_total;

    printf("Digite a largura do terreno (em metros): ");
    scanf("%f", &largura);

    printf("Digite o comprimento do terreno (em metros): ");
    scanf("%f", &comprimento);

    printf("Digite o preço do metro quadrado (em reais): ");
    scanf("%f", &preco_metro_quadrado);

    area = largura * comprimento;

    preco_total = area * preco_metro_quadrado;

    printf("A area do terreno e: %.2f metros quadrados.\n", area);
    printf("O preço total do terreno e: R$ %.2f\n", preco_total);

    return 0;
}

