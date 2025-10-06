#include <stdio.h>
#include <string.h>

int main() {
    char str1[20], str2[20];

    printf("Digite a primeira string: ");
    fgets(str1, 20, stdin);
    printf("Digite a segunda string: ");
    fgets(str2, 20, stdin);

    if (strcmp(str1, str2) == 0)
        printf("As strings sao iguais!\n");
    else
        printf("As strings sao diferentes!\n");

    return 0;
}

