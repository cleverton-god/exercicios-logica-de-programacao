#include <stdio.h>

int main() {
    float preco, total = 0;
    
    while (1) {
        printf("Digite o preco do produto (ou -1 para finalizar): ");
        scanf("%f", &preco);
        
        if (preco == -1) {
            break;
        }else if (preco < -1) { 
        	printf("valor invalido\n");
        	continue;
		}
        total += preco;
    }
    
    printf("Total da compra: R$ %.2f\n", total);
    return 0;
}

