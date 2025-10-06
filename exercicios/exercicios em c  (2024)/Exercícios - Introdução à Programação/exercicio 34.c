#include <stdio.h>

int main() {
    float valorPrestacao;
    int diasAtraso;
    
    printf("Digite o valor da prestacao: ");
    scanf("%f", &valorPrestacao);
    printf("Digite o numero de dias em atraso: ");
    scanf("%d", &diasAtraso);
    
    float multa = valorPrestacao * 0.02;
    float juros = valorPrestacao * (0.001 * diasAtraso);
    
    printf("Multa: %.2f, Juros: %.2f\n", multa, juros);
    
    return 0;
}

