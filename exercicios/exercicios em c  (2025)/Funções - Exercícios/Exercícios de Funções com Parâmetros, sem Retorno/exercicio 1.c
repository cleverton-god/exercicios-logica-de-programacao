#include <stdio.h>

void verificarMaioridade(int idade) {
    if (idade >= 18) {
        printf("Maior de idade.\n");
    } else {
        printf("Menor de idade.\n");
    }
}

int main() {
    int idade;
    printf("Digite a idade: ");
    scanf("%d", &idade);
    verificarMaioridade(idade);
    return 0;
}
