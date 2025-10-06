#include <stdio.h>

int main() {
    int idade;
    char sexo;

    printf("Digite a idade: ");
    scanf("%d", &idade);
    printf("Digite o sexo (M/F): ");
    scanf(" %c", &sexo);

    if (sexo != 'm' && sexo != 'f') {
        printf("Sexo invalido.\n");
        return 1;
    }

    if (sexo == 'm') {
        if (idade >= 65) {
            printf("Pode se aposentar.\n");
        } else {
            printf("Nao pode se aposentar.\n");
        }
    } else { 
        if (idade >= 62) {
            printf("Pode se aposentar.\n");
        } else {
            printf("Nao pode se aposentar.\n");
        }
    }
    return 0;
}

