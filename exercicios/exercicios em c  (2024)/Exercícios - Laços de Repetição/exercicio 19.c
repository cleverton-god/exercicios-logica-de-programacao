#include <stdio.h>

int main() {
    int populacaoA = 80000, populacaoB = 200000; 
    float taxaA = 0.03, taxaB = 0.015; 
    int anos = 0;

    while (populacaoA < populacaoB) { 
        populacaoA += populacaoA * taxaA; 
        populacaoB += populacaoB * taxaB; 
        anos++; 
    }
    printf("Anos necessarios: %d\n", anos); 
    return 0;
}

