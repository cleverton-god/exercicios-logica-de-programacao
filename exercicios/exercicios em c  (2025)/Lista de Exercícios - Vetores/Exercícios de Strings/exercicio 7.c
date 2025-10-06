#include <stdio.h>
#include <string.h>

int main() {
    char frase[100], palavra[20];

    printf("Digite uma frase: ");
    fgets(frase, 100, stdin);
    
    printf("Digite a palavra a buscar: ");
    scanf("%s", palavra);

    if (strstr(frase, palavra))
        printf("Palavra encontrada!\n");
    else
        printf("Palavra nao encontrada.\n");

    return 0;
}

