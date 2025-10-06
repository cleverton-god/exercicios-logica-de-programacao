#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAM_MAX 100

void removerQuebraDeLinha(char *str) {
    int tamanho = strlen(str);
    if (tamanho > 0 && str[tamanho - 1] == '\n') {
        str[tamanho - 1] = '\0';
    }
}

void criptografarMensagem(char *mensagem, int deslocamento) {
    for (int i = 0; mensagem[i] != '\0'; i++) {
        if (isalpha(mensagem[i])) {
            char base = isupper(mensagem[i]) ? 'A' : 'a';
            mensagem[i] = (mensagem[i] - base + deslocamento) % 26 + base;
        }
    }
}

void descriptografarMensagem(char *mensagem, int deslocamento) {
    for (int i = 0; mensagem[i] != '\0'; i++) {
        if (isalpha(mensagem[i])) {
            char base = isupper(mensagem[i]) ? 'A' : 'a';
            mensagem[i] = (mensagem[i] - base - deslocamento + 26) % 26 + base;
        }
    }
}

int main() {
    char mensagem[TAM_MAX];
    int deslocamento;

    printf("Digite uma mensagem: ");
    fgets(mensagem, TAM_MAX, stdin);
    removerQuebraDeLinha(mensagem);

    printf("Digite o deslocamento: ");
    scanf("%d", &deslocamento);

    criptografarMensagem(mensagem, deslocamento);
    printf("Mensagem criptografada: %s\n", mensagem);

    descriptografarMensagem(mensagem, deslocamento);
    printf("Mensagem descriptografada: %s\n", mensagem);

    return 0;
}

