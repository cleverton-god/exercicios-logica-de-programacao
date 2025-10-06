#include <stdio.h>

int main() {
    int soma = 0, num; 
    for (int i = 0; i < 5; i++) { 
        printf("Digite um numero: ");
        scanf("%d", &num); 
        soma += num; 
    }
    printf("Media: %.2f\n", (float)soma / 5);
    return 0;
}

