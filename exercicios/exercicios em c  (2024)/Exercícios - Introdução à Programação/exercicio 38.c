#include <stdio.h>

int main() {
    int horas, minutos, segundos;
    
    printf("Digite o numero de horas: ");
    scanf("%d", &horas);
    printf("Digite o numero de minutos: ");
    scanf("%d", &minutos);
    printf("Digite o numero de segundos: ");
    scanf("%d", &segundos);
    
    int totalSegundos = (horas * 3600) + (minutos * 60) + segundos;
    printf("Total em segundos: %d\n", totalSegundos);
    
    return 0;
}

