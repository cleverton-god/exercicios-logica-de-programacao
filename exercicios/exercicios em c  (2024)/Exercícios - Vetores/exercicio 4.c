#include <stdio.h>

int main() {
    int vetor[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int pares = 0, impares = 0;
    
    for (int i = 0; i < 10; i++) {
        if (vetor[i] % 2 == 0) {
            pares++;
        } else {
            impares++;
        }
    }
    
    printf("Numeros pares: %d\n", pares);
    printf("Numeros impares: %d\n", impares);
    
    return 0;
}
