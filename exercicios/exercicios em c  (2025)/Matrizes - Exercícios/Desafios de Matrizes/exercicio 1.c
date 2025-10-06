#include <stdio.h>

#define TAM 3

void lerMatriz(int mat[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
}

void imprimirMatriz(int mat[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++)
            printf("%d\t", mat[i][j]);
        printf("\n");
    }
}

void somar(int a[TAM][TAM], int b[TAM][TAM], int res[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            res[i][j] = a[i][j] + b[i][j];
}

void subtrair(int a[TAM][TAM], int b[TAM][TAM], int res[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            res[i][j] = a[i][j] - b[i][j];
}

void multiplicar(int a[TAM][TAM], int b[TAM][TAM], int res[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++) {
            res[i][j] = 0;
            for (int k = 0; k < TAM; k++)
                res[i][j] += a[i][k] * b[k][j];
        }
}

void escalar(int mat[TAM][TAM], int esc, int res[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            res[i][j] = mat[i][j] * esc;
}

void transposta(int mat[TAM][TAM], int res[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            res[j][i] = mat[i][j];
}

int main() {
    int op, matriz1[TAM][TAM], matriz2[TAM][TAM], resultado[TAM][TAM], esc;

    do {
        printf("\n--- Calculadora de Matrizes 3x3 ---\n");
        printf("1. Somar duas matrizes\n2. Subtrair duas matrizes\n3. Multiplicar duas matrizes\n");
        printf("4. Multiplicar matriz por escalar\n5. Calcular transposta\n6. Sair\nOpcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("Digite a primeira matriz:\n");
                lerMatriz(matriz1);
                printf("Digite a segunda matriz:\n");
                lerMatriz(matriz2);
                somar(matriz1, matriz2, resultado);
                printf("Resultado da soma:\n");
                imprimirMatriz(resultado);
                break;
            case 2:
                printf("Digite a primeira matriz:\n");
                lerMatriz(matriz1);
                printf("Digite a segunda matriz:\n");
                lerMatriz(matriz2);
                subtrair(matriz1, matriz2, resultado);
                printf("Resultado da subtracao:\n");
                imprimirMatriz(resultado);
                break;
            case 3:
                printf("Digite a primeira matriz:\n");
                lerMatriz(matriz1);
                printf("Digite a segunda matriz:\n");
                lerMatriz(matriz2);
                multiplicar(matriz1, matriz2, resultado);
                printf("Resultado da multiplicacao:\n");
                imprimirMatriz(resultado);
                break;
            case 4:
                printf("Digite a matriz:\n");
                lerMatriz(matriz1);
                printf("Digite o escalar: ");
                scanf("%d", &esc);
                escalar(matriz1, esc, resultado);
                printf("Resultado:\n");
                imprimirMatriz(resultado);
                break;
            case 5:
                printf("Digite a matriz:\n");
                lerMatriz(matriz1);
                transposta(matriz1, resultado);
                printf("Transposta:\n");
                imprimirMatriz(resultado);
                break;
            case 6:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }

    } while (op != 6);

    return 0;
}
