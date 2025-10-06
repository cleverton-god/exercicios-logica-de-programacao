#include <stdio.h>
#include <string.h> 

int main() {
    char nome[100];
    float notas[7];
    float soma = 0.0, melhorNota, piorNota, media;
    
    printf("Atleta: ");
    fgets(nome, sizeof(nome), stdin);
    
    nome[strcspn(nome, "\n")] = 0;
    
    for(int i = 0; i < 7; i++) {
        printf("Nota %d: ", i + 1);
        scanf("%f", &notas[i]);
    }
    
    melhorNota = notas[0];
    piorNota = notas[0];
    
    for(int i = 1; i < 7; i++) {
        if (notas[i] > melhorNota) {
            melhorNota = notas[i];
        }
        if (notas[i] < piorNota) {
            piorNota = notas[i];
        }
    }
    
    for(int i = 0; i < 7; i++) {
        if (notas[i] != melhorNota && notas[i] != piorNota) {
            soma += notas[i];
        }
    }
    
    media = soma / 5.0; 
    
    printf("\nResultado final:\n");
    printf("Atleta: %s\n", nome);
    printf("Melhor nota: %.1f\n", melhorNota);
    printf("Pior nota: %.1f\n", piorNota);
    printf("Media: %.2f\n", media);
    
    return 0;
}

