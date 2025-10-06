#include <stdio.h>

void exibirMenu() {
    printf("\nMenu:\n");
    printf("1 - Opcao Um\n");
    printf("2 - Opcao Dois\n");
    printf("3 - Sair\n");
}

int main() {
    int escolha;

    do {
        exibirMenu();
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Voce escolheu a Opcao Um.\n");
                break;
            case 2:
                printf("Voce escolheu a Opcao Dois.\n");
                break;
            case 3:
                printf("Saindo do menu...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (escolha != 3);

    return 0;
}
