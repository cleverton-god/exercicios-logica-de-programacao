#include <stdio.h>

int main() {
    int vetor[] = {1, 2, 3, 2, 4, 2, 5, 2};
    int numero = 2;
    int contagem = 0;
    
    for (int i = 0; i < 8; i++) {
        if (vetor[i] == numero) {
            contagem++;
        }
    }
    
    printf("O numero %d aparece %d vezes no vetor.\n", numero, contagem);
    
    return 0;
}
