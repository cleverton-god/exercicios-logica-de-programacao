#include <stdio.h>

int main() {
    float valorReais, cotacaoDolar;
    
    printf("Digite o valor em reais: ");
    scanf("%f", &valorReais);
    printf("Digite a cotacao do dolar: ");
    scanf("%f", &cotacaoDolar);
    
    float valorDolares = valorReais / cotacaoDolar;
    printf("O valor em dolares e: %.2f\n", valorDolares);
    
    return 0;
}

