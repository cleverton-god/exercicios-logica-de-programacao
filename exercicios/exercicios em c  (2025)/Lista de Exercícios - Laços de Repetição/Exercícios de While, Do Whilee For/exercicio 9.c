#include <stdio.h>
#include <string.h>

int main() {
    char usuario[50], senha[50];
    const char senha_correta[] = "1234";
	
	while (1) {
    printf("Digite o nome de usuario: ");
    scanf("%s", usuario);

    printf("Digite a senha: ");
    scanf("%s", senha);

    if (strcmp(senha, senha_correta) == 0) {
        printf("Acesso permitido\n");
        break;
    } else {
        printf("Senha incorreta\n");
    }
	}
    return 0;
}

