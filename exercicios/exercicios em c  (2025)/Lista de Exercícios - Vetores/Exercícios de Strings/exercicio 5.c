#include <stdio.h>

int main() {
    char palavra[50];
    int i = 0, contador = 0;

    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    while (palavra[i] != '\0') {
        contador++;
        i++;
    }

    printf("A palavra tem %d letras.\n", contador);
    return 0;
}

