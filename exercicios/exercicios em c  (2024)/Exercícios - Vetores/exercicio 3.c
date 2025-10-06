#include <stdio.h>

int main() {
    float vetor[] = {1.5, 2.7, 3.1, 4.2, 5.0};
    float soma = 0.0;
    
    for (int i = 0; i < 5; i++) {
        soma += vetor[i];
    }
    
    float media = soma / 5;
    
    printf("A media dos valores e: %.2f\n", media);
    
    return 0;
}
