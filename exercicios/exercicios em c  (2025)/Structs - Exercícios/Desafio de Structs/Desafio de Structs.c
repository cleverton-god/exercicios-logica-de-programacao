#include <stdio.h>
#include <string.h>

// Estrutura do aluno
struct Aluno {
    char nome[50];
    int matricula;
    float notas[3];
    float media;
};

// Função para calcular média
float calcularMedia(float notas[], int tamanho) {
    float soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += notas[i];
    }
    return soma / tamanho;
}

// Função para verificar situação
char* verificarSituacao(float media) {
    if (media >= 7.0)
        return "Aprovado";
    else
        return "Reprovado";
}

// Função para mostrar dados do aluno
void mostrarAluno(struct Aluno a) {
    printf("\n--- Dados do Aluno ---\n");
    printf("Nome: %s\n", a.nome);
    printf("Matricula: %d\n", a.matricula);
    printf("Media: %.2f\n", a.media);
    printf("Situacao: %s\n", verificarSituacao(a.media));
}

int main() {
    struct Aluno alunos[5];

    printf("Cadastro de 5 Alunos\n");
    for (int i = 0; i < 5; i++) {
        printf("\n--- Aluno %d ---\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", alunos[i].nome);
        printf("Matricula: ");
        scanf("%d", &alunos[i].matricula);

        for (int j = 0; j < 3; j++) {
            printf("Nota %d: ", j + 1);
            scanf("%f", &alunos[i].notas[j]);
        }

        alunos[i].media = calcularMedia(alunos[i].notas, 3);
    }

    printf("\n\n====== LISTAGEM FINAL ======\n");
    for (int i = 0; i < 5; i++) {
        mostrarAluno(alunos[i]);
    }

    return 0;
}
