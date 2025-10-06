#include <stdio.h>

int main() {
    float valorProduto; 

    printf("Digite o valor do produto: ");
    scanf("%f", &valorProduto);  

    float desconto = valorProduto * 0.15;  
    float novoPreco = valorProduto - desconto;  

    printf("O novo preço do produto com desconto de 15%% e: %.2f\n", novoPreco);  

    return 0;
}

