#include <stdio.h>
#include <string.h>

int verificarSenha(char senha[]) {
    return strcmp(senha, "123456") == 0;
}

int main() {
    char senha[20];
    printf("Digite a senha: ");
    scanf("%s", senha);
    if (verificarSenha(senha))
        printf("Acesso permitido.\n");
    else
        printf("Acesso negado.\n");
    return 0;
}
