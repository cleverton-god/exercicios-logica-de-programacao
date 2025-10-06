#include <stdio.h>

int main() {
    int segundos,horas,minutos,restante_segundos;

   
    printf("Digite o numero de segundos\n");
    scanf("%d",&segundos);

    
    horas=segundos/3600;
    minutos=(segundos%3600)/60;
    restante_segundos=segundos%60;

    
    printf("%d segundos correspondem a: %d horas, %d minutos e %d segundos.\n", segundos, horas, minutos, restante_segundos);

    return 0;
}

