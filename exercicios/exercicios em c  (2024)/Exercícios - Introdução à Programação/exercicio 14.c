#include <stdio.h>

int main() {
    float valor; 

    printf("Digite um valor em reais: ");
    scanf("%f", &valor);  

    float aumento = valor * 0.10;  
    float valorComAumento = valor + aumento;  

    printf("O valor com um aumento de 10%% e: %.2f\n", valorComAumento);  

    return 0;
}

