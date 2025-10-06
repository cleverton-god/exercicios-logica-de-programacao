#include <stdio.h>

int main() {
    char letra;
    printf("Digite uma letra (f ou m): ");
    scanf(" %c", &letra);
    
    if (letra == 'f') {
        printf("Feminino\n");
    } else if (letra == 'm') {
        printf("Masculino\n");
    } else {
        printf("Letra invalida\n");
    }

    return 0;
}

