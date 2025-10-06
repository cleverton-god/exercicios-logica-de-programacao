#include <stdio.h>

int main() {
    int maior; 
    printf("Digite 5 numeros:\n");
    for (int i = 0; i < 5; i++) { 
        int num; 
        scanf("%d", &num); 
        if (i == 0 || num > maior) { 
            maior = num; 
        }
    }
    printf("Maior numero: %d\n", maior); 
    return 0;
}

