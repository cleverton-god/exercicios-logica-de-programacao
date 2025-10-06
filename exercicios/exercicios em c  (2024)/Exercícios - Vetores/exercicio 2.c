#include <stdio.h>

int main() {
    int vetor[] = {1, 2, 3, 4, 5};
    int soma = 0;
    
    for (int i = 0; i < 5; i++) {
        soma += vetor[i];
    }
    
    printf("A soma dos elementos e: %d\n", soma);
    
    return 0;
}
