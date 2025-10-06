#include <stdio.h>

int main() {
    int resposta, pontos = 0;

    printf("Responda as seguintes perguntas com 1 para SIM e 0 para NAO:\n");

    printf("Telefonou para a vitima? ");
    scanf("%d", &resposta);
    pontos += resposta;

    printf("Esteve no local do crime? ");
    scanf("%d", &resposta);
    pontos += resposta;

    printf("Mora perto da vitima? ");
    scanf("%d", &resposta);
    pontos += resposta;

    printf("Devia para a vitima? ");
    scanf("%d", &resposta);
    pontos += resposta;

    printf("Ja trabalhou com a vitima? ");
    scanf("%d", &resposta);
    pontos += resposta;

    if (pontos == 2) {
        printf("Classificacao: Suspeita\n");
    } else if (pontos >= 3 && pontos <= 4) {
        printf("Classificacao: Cumplice\n");
    } else if (pontos == 5) {
        printf("Classificacao: Assassino\n");
    } else {
        printf("Classificacao: Inocente\n");
    }

    return 0;
}

