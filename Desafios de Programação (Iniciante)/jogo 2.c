#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8
#define MINES 10

void inicializaTabuleiro(char tabuleiro[SIZE][SIZE], int minas[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++) {
            tabuleiro[i][j] = '.';
            minas[i][j] = 0;
        }
}

void distribuiMinas(int minas[SIZE][SIZE]) {
    int minasColocadas = 0;
    while (minasColocadas < MINES) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        if (minas[x][y] == 0) {
            minas[x][y] = 1;
            minasColocadas++;
        }
    }
}

void contaMinasAdjacentes(int minas[SIZE][SIZE], int contagem[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (minas[i][j] == 1) {
                for (int x = -1; x <= 1; x++) {
                    for (int y = -1; y <= 1; y++) {
                        if (x == 0 && y == 0) continue;
                        int novoX = i + x;
                        int novoY = j + y;
                        if (novoX >= 0 && novoX < SIZE && novoY >= 0 && novoY < SIZE) {
                            contagem[novoX][novoY]++;
                        }
                    }
                }
            }
        }
    }
}

void imprimeTabuleiro(char tabuleiro[SIZE][SIZE]) {
    printf("  0 1 2 3 4 5 6 7\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char tabuleiro[SIZE][SIZE];
    int minas[SIZE][SIZE] = {0};
    int contagem[SIZE][SIZE] = {0};
    int jogoAtivo = 1;

    srand(time(NULL));

    inicializaTabuleiro(tabuleiro, minas);
    distribuiMinas(minas);
    contaMinasAdjacentes(minas, contagem);

    while (jogoAtivo) {
        imprimeTabuleiro(tabuleiro);
        int x, y;
        printf("Escolha uma celula (linha coluna): ");
        scanf("%d %d", &x, &y);

        if (x < 0 || x >= SIZE || y < 0 || y >= SIZE) {
            printf("Posicao invalida! Tente novamente.\n");
            continue;
        }

        if (minas[x][y] == 1) {
            printf("Voce encontrou uma mina! Fim de jogo.\n");
            jogoAtivo = 0;
        } else {
            tabuleiro[x][y] = '0' + contagem[x][y];
            if (tabuleiro[x][y] == '0') {
                tabuleiro[x][y] = ' ';
            }
        }

        
        int vencedor = 1;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (minas[i][j] == 0 && tabuleiro[i][j] == '.') {
                    vencedor = 0;
                }
            }
        }
        if (vencedor) {
            printf("Parabens! Voce revelou todas as celulas sem minas.\n");
            jogoAtivo = 0;
        }
    }

    return 0;
}
