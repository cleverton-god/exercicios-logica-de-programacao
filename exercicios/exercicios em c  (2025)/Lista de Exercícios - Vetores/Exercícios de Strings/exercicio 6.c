#include <stdio.h>
#include <string.h>

int main() {
    char str[50], temp;
    int i, j;

    printf("Digite uma string: ");
    scanf("%s", str);

    j = strlen(str) - 1;
    for (i = 0; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    printf("String invertida: %s\n", str);
    return 0;
}

