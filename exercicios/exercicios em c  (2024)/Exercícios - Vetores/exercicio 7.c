#include <stdio.h>

int main() {
    int vetor[] = {10, 5, 8, 2, 15};
    int maior = vetor[0];
    int menor = vetor[0];
    
    for (int i = 1; i < 5; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
        }
        if (vetor[i] < menor) {
            menor = vetor[i];
        }
    }
    
    printf("O maior valor e: %d\n", maior);
    printf("O menor valor e: %d\n", menor);
    
    return 0;
}
