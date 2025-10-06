#include <stdio.h>

int main() {
    char turno;
    printf("Digite o turno em que estuda (m - matutino, v - vespertino, n - noturno): ");
    scanf(" %c", &turno);
    
    if (turno == 'm') {
        printf("Bom Dia!\n");
    } else if (turno == 'v') {
        printf("Boa Tarde!\n");
    } else if (turno == 'n') {
        printf("Boa Noite!\n");
    } else {
        printf("Valor Invalido!\n");
    }

    return 0;
}

