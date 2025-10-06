#include <stdio.h>
#include <string.h>

int verificarPalindromo(char s[]) {
    int i = 0, j = strlen(s) - 1;
    while (i < j) {
        if (s[i] != s[j])
            return 0;
        i++;
        j--;
    }
    return 1;
}

int main() {
    char s[100];
    printf("Digite uma palavra: ");
    scanf("%s", s);
    if (verificarPalindromo(s))
        printf("E um palindromo.\n");
    else
        printf("Nao e palindromo.\n");
    return 0;
}
