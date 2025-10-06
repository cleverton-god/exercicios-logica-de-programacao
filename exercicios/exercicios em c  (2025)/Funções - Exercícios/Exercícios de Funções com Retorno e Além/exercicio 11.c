#include <stdio.h>
#include <string.h>

void inverterString(char s[]) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

int main() {
    char s[100];
    printf("Digite uma string: ");
    scanf("%s", s);
    inverterString(s);
    printf("Invertida: %s\n", s);
    return 0;
}
