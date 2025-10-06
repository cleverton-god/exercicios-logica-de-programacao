#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TENTATIVAS 6
#define PALAVRAS 5

void mostrar_forca(int tentativas) {
    switch (tentativas) {
        case 0: printf("  +---+\n  |   |\n      |\n      |\n      |\n      |\n=========\n"); break;
        case 1: printf("  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n=========\n"); break;
        case 2: printf("  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n=========\n"); break;
        case 3: printf("  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n=========\n"); break;
        case 4: printf("  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n=========\n"); break;
        case 5: printf("  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n=========\n"); break;
        case 6: printf("  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n=========\n"); break;
    }
}

int main() {
    char *palavras[PALAVRAS] = {"banana", "abacaxi", "laranja", "uva", "manga"};
    char palavra[20];
    char letra;
    int tentativas = 0;
    int acertos = 0;
    int tamanho_palavra;
    char palpite[20];
    int i, j;

    srand(time(NULL));
    strcpy(palavra, palavras[rand() % PALAVRAS]);
    tamanho_palavra = strlen(palavra);

    for (i = 0; i < tamanho_palavra; i++) {
        palpite[i] = '_';
    }
    palpite[i] = '\0';

    while (tentativas < MAX_TENTATIVAS && acertos < tamanho_palavra) {
        printf("\nPalavra: %s\n", palpite);
        mostrar_forca(tentativas);
        printf("Tentativas restantes: %d\n", MAX_TENTATIVAS - tentativas);
        printf("Adivinhe uma letra: ");
        scanf(" %c", &letra);

        int letra_certa = 0;
        for (j = 0; j < tamanho_palavra; j++) {
            if (palavra[j] == letra) {
                palpite[j] = letra;
                letra_certa = 1;
                acertos++;
            }
        }

        if (!letra_certa) {
            tentativas++;
        }
    }

    if (acertos == tamanho_palavra) {
        printf("\nParabens! Voce acertou a palavra: %s\n", palavra);
    } else {
        printf("\nVoce perdeu! A palavra era: %s\n", palavra);
        mostrar_forca(tentativas);
    }

    return 0;
}

