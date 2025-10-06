#include <stdio.h>
#include <string.h>

int contarCaracter(char s[], char c) {
    int cont = 0;
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] == c)
            cont++;
    return cont;
}

int main() {
    char s[100], c;
    printf("Digite uma string: ");
    scanf("%s", s);
    printf("Digite o caractere: ");
    scanf(" %c", &c);
    printf("O caractere '%c' aparece %d vezes.\n", c, contarCaracter(s, c));
    return 0;
}
