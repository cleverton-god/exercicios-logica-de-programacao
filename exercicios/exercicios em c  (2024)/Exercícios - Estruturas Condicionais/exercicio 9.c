#include <stdio.h>

int main() {
    float nota;
    printf("Digite a nota do aluno: ");
    scanf("%f", &nota);
    
    if (nota >= 7) {
        printf("Aprovado\n");
    } else if (nota < 5) {
        printf("Reprovado\n");
    } else {
        printf("Recuperacao\n");
    }

    return 0;
}

