#include <stdio.h>

int main() {
    float velocidade, limite, multa = 0;

    printf("Digite a velocidade do carro: ");
    scanf("%f", &velocidade);
    printf("Digite a velocidade maxima da via: ");
    scanf("%f", &limite);

    if (velocidade <= limite) {
        printf("Sem multa.\n");
    } else {
        float excesso = velocidade - limite;
        if (excesso <= limite * 0.20) {
            multa = 130;
        } else if (excesso <= limite * 0.50) {
            multa = 195;
        } else {
            multa = 880;
        }
        printf("Multa: R$ %.2f\n", multa);
    }
    return 0;
}

