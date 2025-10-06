#include <stdio.h>

int main() {
    int vetor[] = {1, 2, 3, 4, 5};
    int temp;
    int tamanho = 5;
    
    for (int i = 0; i < tamanho / 2; i++) {
        temp = vetor[i];
        vetor[i] = vetor[tamanho - 1 - i];
        vetor[tamanho - 1 - i] = temp;
    }
    
    printf("Vetor invertido: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    
    return 0;
}
