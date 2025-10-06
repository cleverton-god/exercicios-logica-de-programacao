#include <stdio.h>

int main() {
    int ano;

    printf("Digite um ano: ");
    scanf("%d", &ano);

    if (ano % 400 == 0) {
        printf("O ano %d e bissexto.\n", ano);
    } else if (ano % 100 == 0) {
        printf("O ano %d NAO e bissexto.\n", ano);
    } else if (ano % 4 == 0) {
        printf("O ano %d e bissexto.\n", ano);
    } else {
        printf("O ano %d NAO e bissexto.\n", ano);
    }

    return 0;
}

