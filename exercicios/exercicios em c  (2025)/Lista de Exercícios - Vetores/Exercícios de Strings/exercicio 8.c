#include <stdio.h>

int main() {
    char str[100], c1, c2;
    int i, escolha, cont = 0;

    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);

    printf("Digite o caractere a ser substituido: ");
    scanf(" %c", &c1);

    printf("Digite o novo caractere: ");
    scanf(" %c", &c2);

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == c1) {
            cont++;
        }
    }

    if (cont == 0) {
        printf("Caractere '%c' nao encontrado na string.\n", c1);
        return 0;
    }

    printf("Existem %d ocorrencias de '%c'. Escolha qual deseja substituir (1-%d): ", cont, c1, cont);
    scanf("%d", &escolha);

    if (escolha < 1 || escolha > cont) {
        printf("Escolha inválida.\n");
        return 0;
    }

    cont = 0;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == c1) {
            cont++;
            if (cont == escolha) {
                str[i] = c2;
                break;
            }
        }
    }

    printf("String modificada: %s\n", str);

    return 0;
}

