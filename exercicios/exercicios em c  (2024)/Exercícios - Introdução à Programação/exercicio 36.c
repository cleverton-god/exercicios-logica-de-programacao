#include <stdio.h>

int main() {
    float largura, comprimento, precoMetroQuadrado;
    
    printf("Digite a largura do terreno (em metros): ");
    scanf("%f", &largura);
    printf("Digite o comprimento do terreno (em metros): ");
    scanf("%f", &comprimento);
    printf("Digite o preco do metro quadrado: ");
    scanf("%f", &precoMetroQuadrado);
    
    float area = largura * comprimento;
    float precoTotal = area * precoMetroQuadrado;
    
    printf("O preco total do terreno e: %.2f\n", precoTotal);
    
    return 0;
}

