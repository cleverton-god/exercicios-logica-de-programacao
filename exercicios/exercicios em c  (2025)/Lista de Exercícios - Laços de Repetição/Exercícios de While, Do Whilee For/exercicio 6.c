#include <stdio.h>

int main() {
    float valor=0;
	float desconto=0;
	float valor_final=0;
	float total=0;

    while (1) {
        printf("Digite o valor da compra (ou -1 para sair): ");
        scanf("%f", &valor);
        
        if (valor == -1) {
            break;
        }

        printf("Digite o percentual de desconto: ");
        scanf("%f", &desconto);

        valor_final = valor - (valor * (desconto / 100));
        printf("Valor final apos desconto: R$ %.2f\n", valor_final);
        total += valor_final;
        printf("total:%.2f\n",total);
    }
    
    return 0;
}

