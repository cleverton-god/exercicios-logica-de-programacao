#include <stdio.h>
#include <stdlib.h>

char tabuleiro[3][3];
char jogador = 'X';

void inicializar_tabuleiro() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}

void imprimir_tabuleiro() {
    printf(" %c | %c | %c\n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
}

int verifica_vencedor() {
    
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' ') {
            return 1;
        }
    }

   
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != ' ') {
            return 1;
        }
    }


    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ') {
        return 1;
    }
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' ') {
        return 1;
    }

 
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabuleiro[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 2;
}

int main() {
    int linha, coluna;
    int resultado;

    inicializar_tabuleiro();

    while (1) {
        imprimir_tabuleiro();
        printf("Jogador %c, escolha uma posicao (linha coluna): ", jogador);
        scanf("%d %d", &linha, &coluna);

        if (tabuleiro[linha-1][coluna-1] != ' ') {
            printf("Posicao ocupada, tente novamente.\n");
            continue;
        }

        tabuleiro[linha-1][coluna-1] = jogador;

        resultado = verifica_vencedor();
        if (resultado == 1) {
            imprimir_tabuleiro();
            printf("Jogador %c venceu!\n", jogador);
            break;
        } else if (resultado == 2) {
            imprimir_tabuleiro();
            printf("Empate!\n");
            break;
        }

        if (jogador == 'X') {
            jogador = 'O';
        } else {
            jogador = 'X';
        }
    }

    return 0;
}
