#include <stdio.h>

int main() {
    float nota;
    int faltas, total_aulas;

    printf("Digite a nota final: ");
    scanf("%f", &nota);
    printf("Digite o numero de faltas: ");
    scanf("%d", &faltas);
    printf("Digite o total de aulas: ");
    scanf("%d", &total_aulas);

    if (nota >= 7 && faltas <= (total_aulas * 0.25)) {
        printf("Aprovado.\n");
    } else if (nota < 7) {
        printf("Reprovado por nota.\n");
    } else {
        printf("Reprovado por faltas.\n");
    }
    return 0;
}

