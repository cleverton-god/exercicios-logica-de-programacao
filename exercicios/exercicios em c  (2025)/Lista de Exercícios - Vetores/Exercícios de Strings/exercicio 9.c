#include <stdio.h>
#include <string.h>

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void permutar(char *str, int l, int r) {
    if (l == r)
        printf("%s\n", str);
    else {
        for (int i = l; i <= r; i++) {
            swap(&str[l], &str[i]);
            permutar(str, l + 1, r);
            swap(&str[l], &str[i]); 
        }
    }
}

int main() {
    char palavra[20];

    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    int n = strlen(palavra);
    permutar(palavra, 0, n - 1);

    return 0;
}

