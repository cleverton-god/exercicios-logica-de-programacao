#include <stdio.h>

void repetirFrase(char frase[], int vezes) {
    for (int i = 0; i < vezes; i++) {
        printf("%s\n", frase);
    }
}

int main() {
    char frase[100];
    int vezes;

    printf("Digite uma frase: ");
    fflush(stdin);
    fgets(frase, sizeof(frase), stdin);

    printf("Quantas vezes repetir: ");
    scanf("%d", &vezes);

    repetirFrase(frase, vezes);
    return 0;
}
