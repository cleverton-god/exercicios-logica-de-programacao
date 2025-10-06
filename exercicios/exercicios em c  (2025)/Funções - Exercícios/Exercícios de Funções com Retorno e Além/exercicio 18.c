#include <stdio.h>

int ehAnoBissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

int main() {
    int ano;
    printf("Digite um ano: ");
    scanf("%d", &ano);
    if (ehAnoBissexto(ano))
        printf("Ano bissexto.\n");
    else
        printf("Nao e bissexto.\n");
    return 0;
}
