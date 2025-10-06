#include <stdio.h>

int main() {
    int populacaoA, populacaoB;
    float taxaA, taxaB;

   
    printf("Digite a populacao do pais A: ");
    scanf("%d", &populacaoA);
    printf("Digite a taxa de crescimento do pais A (em decimal): ");
    scanf("%f", &taxaA);

    printf("Digite a populacao do pais B: ");
    scanf("%d", &populacaoB);
    printf("Digite a taxa de crescimento do pais B (em decimal): ");
    scanf("%f", &taxaB);

    int anos = 0;
    while (populacaoA < populacaoB) { 
        populacaoA += populacaoA * taxaA; 
        populacaoB += populacaoB * taxaB; 
        anos++; 
    }
    printf("Anos necessarios: %d\n", anos);
    return 0;
}

