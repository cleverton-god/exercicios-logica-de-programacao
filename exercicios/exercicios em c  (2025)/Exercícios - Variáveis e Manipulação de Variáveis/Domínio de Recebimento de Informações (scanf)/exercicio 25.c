#include <stdio.h>

int main() {
    float distancia, tempo, velocidade_media;

    printf("Digite a distancia percorrida (em km): ");
    scanf("%f", &distancia);

    printf("Digite o tempo gasto (em horas): ");
    scanf("%f", &tempo);

    velocidade_media = distancia / tempo;

    printf("A velocidade media da viagem e %.2f km/h.\n", velocidade_media);

    return 0;
}

