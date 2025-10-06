#include <stdio.h>
#include <string.h>

int main() {
    char usuario[50], senha[50]; 
    do {
        printf("Digite o nome de usuario: ");
        scanf("%s", usuario); 
        printf("Digite a senha: ");
        scanf("%s", senha); 
        
        if (strcmp(usuario, senha) == 0) { 
            printf("Erro: A senha nao pode ser igual ao nome de usuario.\n");
        }
    } while (strcmp(usuario, senha) == 0); 
    return 0;
}

