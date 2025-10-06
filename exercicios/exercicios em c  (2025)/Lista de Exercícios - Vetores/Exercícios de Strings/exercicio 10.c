#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAM_MINIMO 8

int verificarSenha(const char *senha) {
    int temMaiuscula = 0, temMinuscula = 0, temNumero = 0, temEspecial = 0;
    int tamanho = strlen(senha);

    if (tamanho > 0 && senha[tamanho - 1] == '\n') {
        tamanho--; // Remove o '\n' do tamanho
    }

    if (tamanho < TAM_MINIMO) {
        printf("? Senha muito curta! Deve ter pelo menos %d caracteres.\n", TAM_MINIMO);
        return 0;
    }

    for (int i = 0; i < tamanho; i++) {
        if (isupper(senha[i])) temMaiuscula = 1;
        else if (islower(senha[i])) temMinuscula = 1;
        else if (isdigit(senha[i])) temNumero = 1;
        else if (strchr("!@#$%^&*()-_=+[]{};:'\",.<>?/|\\", senha[i])) temEspecial = 1;
    }

    if (!temMaiuscula) printf("? Falta pelo menos uma letra MAIUSCULA.\n");
    if (!temMinuscula) printf("? Falta pelo menos uma letra minuscula.\n");
    if (!temNumero)    printf("? Falta pelo menos um numero.\n");
    if (!temEspecial)  printf("? Falta pelo menos um caractere especial (!@#$...).\n");

    return temMaiuscula && temMinuscula && temNumero && temEspecial;
}

int main() {
    char senha[100];

    printf("Digite uma senha: ");
    fgets(senha, sizeof(senha), stdin);

    if (verificarSenha(senha)) {
        printf("? Senha valida!\n");
    } else {
        printf("? Tente novamente com uma senha mais forte.\n");
    }

    return 0;
}

