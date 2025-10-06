#include <stdio.h>

int main() {
    float notas[5];

    for (int i = 0; i < 5; i++) {
        printf("Digite a nota do aluno %d: ", i + 1);
        scanf("%f", &notas[i]);
    }
    
    for (int i = 0; i < 5; i++) {
        printf("Aluno %d: ", i + 1);
        if (notas[i] >= 7.0){
            printf("Aprovado\n");
        }else {
            printf("Reprovado\n");
        }
    }
    
    return 0;
}

