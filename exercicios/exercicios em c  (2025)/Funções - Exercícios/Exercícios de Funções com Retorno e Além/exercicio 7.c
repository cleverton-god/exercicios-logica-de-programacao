#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerarSenha(char senha[], int n) {
    char caracteres[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    for (int i = 0; i < n; i++)
        senha[i] = caracteres[rand() % 62];
    senha[n] = '\0';
}

int main() {
    int n;
    char senha[101];
    srand(time(NULL));
    printf("Tamanho da senha: ");
    scanf("%d", &n);
    gerarSenha(senha, n);
    printf("Senha gerada: %s\n", senha);
    return 0;
}
