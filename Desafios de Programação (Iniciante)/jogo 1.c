#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numeroSecreto, palpite, tentativas = 0, limiteTentativas = 10;
    char jogarNovamente;

  
    srand(time(NULL));

    do {
        
        numeroSecreto = rand() % 100 + 1;
        tentativas = 0;

        printf("Bem-vindo ao jogo de adivinhacao de numeros!\n");
        printf("Eu pensei em um numero entre 1 e 100. Tente adivinhar!\n");

       
        while (tentativas < limiteTentativas) {
            printf("Tentativa %d de %d. Digite seu palpite: ", tentativas + 1, limiteTentativas);
            scanf("%d", &palpite);
            tentativas++;

            if (palpite < numeroSecreto) {
                printf("Seu palpite e menor que o numero secreto.\n");
            } else if (palpite > numeroSecreto) {
                printf("Seu palpite e maior que o numero secreto.\n");
            } else {
                printf("Parabens! Voce adivinhou o numero secreto: %d\n", numeroSecreto);
                break;
            }

            if (tentativas == limiteTentativas) {
                printf("Voce atingiu o limite de tentativas. O numero secreto era: %d\n", numeroSecreto);
            }
        }

        
        printf("Deseja jogar novamente? (s/n): ");
        getchar(); 
        scanf("%c", &jogarNovamente);
    } while (jogarNovamente == 's' || jogarNovamente == 'S');

    printf("Obrigado por jogar!\n\n");
    printf("jogo produzido por cleverton");
    return 0;
}
