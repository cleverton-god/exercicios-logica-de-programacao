#include <stdio.h>

int main() {
    float valor, valor_final;
    int opcao;

 
    printf("Digite o valor da compra: R$ ");
    scanf("%f", &valor);


    printf("\nFormas de pagamento:\n");
    printf("1 - À vista (10%% de desconto)\n");
    printf("2 - À prazo 30 dias (5%% de desconto)\n");
    printf("3 - À prazo 60 dias (sem desconto)\n");
    printf("4 - À prazo 90 dias (5%% de juros)\n");


    printf("\nEscolha a forma de pagamento (1-4): ");
    scanf("%d", &opcao);

   
    if (opcao == 1) {
        valor_final = valor * 0.90;  
    } else if (opcao == 2) {
        valor_final = valor * 0.95;  
    } else if (opcao == 3) {
        valor_final = valor;  
    } else if (opcao == 4) {
        valor_final = valor * 1.05; 
    } else {
        printf("Opcao invalida!\n");
        return 1;
    }

 
    printf("O valor final da compra e: R$ %.2f\n", valor_final);

    return 0;
}

