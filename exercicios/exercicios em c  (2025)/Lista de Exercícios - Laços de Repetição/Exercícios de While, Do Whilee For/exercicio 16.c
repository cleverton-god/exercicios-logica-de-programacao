#include <stdio.h>

int main() {
    float nota;
    int faltas, total_aulas = 0;

    while (1) {
        printf("Digite a nota final do aluno 1  10 (ou -1 para sair): ");
        scanf("%f", &nota);

        if (nota == -1) {
            break;
        }else if (nota < -1 || nota >10) {
        	printf("nota invalida!\n");
        	continue;
		}

        printf("Digite o numero de faltas: ");
        scanf("%d", &faltas);
        printf("Digite o total de aulas: ");
        scanf("%d", &total_aulas);

        if (nota >= 7 && faltas <= (total_aulas * 0.25)) {
            printf("Aluno aprovado!\n");
        } else if (nota < 7) {
            printf("Aluno reprovado por nota.\n");
        } else {
            printf("Aluno reprovado por faltas.\n");
        }
    }

    return 0;
}

