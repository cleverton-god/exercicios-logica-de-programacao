#include <stdio.h>

int main() {
    int voto, candidato1 = 0, candidato2 = 0, candidato3 = 0;

    while (1) {
        printf("Vote em um candidato (1, 2, 3) ou um numero negativo para encerrar: ");
        scanf("%d", &voto);

        if (voto < 0) {
            break;
        } else if (voto == 1) {
            candidato1++;
        } else if (voto == 2) {
            candidato2++;
        } else if (voto == 3) {
            candidato3++;
        } else {
            printf("Voto invalido!\n");
        }
    }

    printf("Resultado da votacao:\n");
    printf("Candidato 1: %d votos\n", candidato1);
    printf("Candidato 2: %d votos\n", candidato2);
    printf("Candidato 3: %d votos\n", candidato3);

    return 0;
}

