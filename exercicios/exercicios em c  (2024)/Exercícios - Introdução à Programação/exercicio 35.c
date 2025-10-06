#include <stdio.h>

int main() {
    float distanciaTotal, consumoMedio;
    
    printf("Digite a distancia total da viagem (em km): ");
    scanf("%f", &distanciaTotal);
    printf("Digite o consumo medio do carro (km/l): ");
    scanf("%f", &consumoMedio);
    
    float litrosNecessarios = distanciaTotal / consumoMedio;
    printf("Serao necessarios %.2f litros para a viagem.\n", litrosNecessarios);
    
    return 0;
}

