#include <stdio.h>

int main() {
    float nota;
    int faltas, total_aulas;
    float limite_faltas;

    printf("Digite a nota final do aluno: ");
    scanf("%f", &nota);

    printf("Digite o total de aulas: ");
    scanf("%d", &total_aulas);

    printf("Digite o numero de faltas: ");
    scanf("%d", &faltas);

    limite_faltas = total_aulas * 0.25;

    if (nota >= 7 && faltas <= limite_faltas) {
        printf("Aluno APROVADO!\n");
    } else if (nota < 7 && faltas > limite_faltas) {
        printf("Aluno REPROVADO por nota e por faltas.\n");
    } else if (nota < 7) {
        printf("Aluno REPROVADO por nota.\n");
    } else {
        printf("Aluno REPROVADO por faltas.\n");
    }

    return 0;
}

