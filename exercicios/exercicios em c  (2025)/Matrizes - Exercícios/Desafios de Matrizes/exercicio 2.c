#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define TAM 3

void embaralhar(int mat[TAM][TAM]) {
    int numeros[9], k = 0;

    for (int i = 0; i < 9; i++) numeros[i] = i + 1;

    // Embaralha os números
    for (int i = 0; i < 9; i++) {
        int r = rand() % 9;
        int temp = numeros[i];
        numeros[i] = numeros[r];
        numeros[r] = temp;
    }

    // Preenche a matriz
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            mat[i][j] = numeros[k++];
}

void imprimir(int mat[TAM][TAM]) {
    printf("\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++)
            printf("%d\t", mat[i][j]);
        printf("\n");
    }
}

bool estaOrdenado(int mat[TAM][TAM]) {
    int esperado = 1;
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            if (mat[i][j] != esperado++) return false;
    return true;
}

int main() {
    int mat[TAM][TAM], lin1, col1, lin2, col2, jogadas = 0;
    srand(time(NULL));
    embaralhar(mat);

    while (1) {
        imprimir(mat);
        if (estaOrdenado(mat)) {
            printf("Parabens! Voce ordenou o cubo em %d jogadas!\n", jogadas);
            break;
        }

        printf("Digite a posicao 1 (linha coluna): ");
        scanf("%d %d", &lin1, &col1);
        printf("Digite a posicao 2 (linha coluna): ");
        scanf("%d %d", &lin2, &col2);

        if (lin1 >= 0 && lin1 < TAM && col1 >= 0 && col1 < TAM &&
            lin2 >= 0 && lin2 < TAM && col2 >= 0 && col2 < TAM) {
            int temp = mat[lin1][col1];
            mat[lin1][col1] = mat[lin2][col2];
            mat[lin2][col2] = temp;
            jogadas++;
        } else {
            printf("Posicoes invalidas! Tente novamente.\n");
        }
    }

    return 0;
}
