#include <stdio.h>

int main() {
    float velocidade_carro, velocidade_maxima, excesso;
    float multa;

    
    printf("Digite a velocidade do carro (km/h): ");
    scanf("%f", &velocidade_carro);

    printf("Digite a velocidade maxima da via (km/h): ");
    scanf("%f", &velocidade_maxima);

 
    excesso = velocidade_carro - velocidade_maxima;

   
    if (excesso > 0) {
       
    if (excesso <= 0.2 * velocidade_maxima) {
            multa = 130;
            printf("Velocidade acima do limite! Multa: R$ %.2f\n", multa);
        } else if (excesso <= 0.5 * velocidade_maxima) {
            multa = 195;
            printf("Velocidade acima do limite! Multa: R$ %.2f\n", multa);
        } else {
            multa = 880;
            printf("Velocidade acima do limite! Multa: R$ %.2f\n", multa);
        }
    } else {
        printf("Voce está dentro do limite de velocidade.\n");
    }

    return 0;
}
