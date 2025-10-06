#include <stdio.h>

int main() {
    float distancia_total, consumo_medio, litros_necessarios;

    printf("Digite a distancia total da viagem (em km): ");
    scanf("%f", &distancia_total);

    printf("Digite o consumo medio do carro (em km/l): ");
    scanf("%f", &consumo_medio);

    litros_necessarios = distancia_total / consumo_medio;

    printf("Voce precisara de %.2f litros de combustivel para a viagem.\n", litros_necessarios);

    return 0;
}

