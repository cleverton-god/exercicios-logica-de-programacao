#include <stdio.h>

int main() {
    int soma = 0, num; 
    for (int i = 0; i < 5; i++) { 
        printf("Digite um numero: ");
        scanf("%d", &num);
        soma += num; 
    }
    printf("Soma: %d, Media: %.2f\n", soma, (float)soma / 5); 
    return 0;
}
