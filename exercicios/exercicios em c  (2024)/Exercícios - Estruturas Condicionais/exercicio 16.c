#include <stdio.h>

int main() {
    int respostas = 0;
    int resposta;
    
    printf("Responda as seguintes perguntas (1 - sim, 0 - nao):\n");
    printf("Telefonou para a vitima? ");
    scanf("%d", &resposta); respostas += resposta;
    printf("Esteve no local do crime? ");
    scanf("%d", &resposta); respostas += resposta;
    printf("Mora perto da vitima? ");
    scanf("%d", &resposta); respostas += resposta;
    printf("Devia para a vitima? ");
    scanf("%d", &resposta); respostas += resposta;
    printf("Ja trabalhou com a vitima? ");
    scanf("%d", &resposta); respostas += resposta;

    if (respostas == 2) {
        printf("Suspeita\n");
    } else if (respostas >= 3 && respostas <= 4) {
        printf("Cumplice\n");
    } else if (respostas == 5) {
        printf("Assassino\n");
    } else {
        printf("Inocente\n");
    }

    return 0;
}

