#include <stdio.h>

int main() {
    int totalSegundos;  

    printf("Digite o total de segundos: ");
    scanf("%d", &totalSegundos);  

    int horas = totalSegundos / 3600;  
    int minutos = (totalSegundos % 3600) / 60;  
    int segundos = totalSegundos % 60;  

    printf("Horas: %d, Minutos: %d, Segundos: %d\n", horas, minutos, segundos);  
    
    return 0;
}

