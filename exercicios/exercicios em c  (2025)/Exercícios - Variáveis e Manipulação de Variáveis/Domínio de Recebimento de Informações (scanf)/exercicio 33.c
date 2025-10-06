#include <stdio.h>

int main() {
    int horas, minutos, segundos, total_segundos;

    printf("Digite o numero de horas: ");
    scanf("%d", &horas);

    printf("Digite o numero de minutos: ");
    scanf("%d", &minutos);

    printf("Digite o numero de segundos: ");
    scanf("%d", &segundos);

    total_segundos = (horas * 3600) + (minutos * 60) + segundos;

    printf("O total de segundos e: %d\n", total_segundos);

    return 0;
}

