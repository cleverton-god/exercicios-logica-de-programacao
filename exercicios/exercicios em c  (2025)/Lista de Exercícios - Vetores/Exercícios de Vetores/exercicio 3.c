#include <stdio.h>

int main() {
    int numeros[7];
	int soma = 0;
    float media = 0;
    
    for (int i = 0; i < 7; i++) {
        printf("Digite um numero: ");
        scanf("%d", &numeros[i]);
        soma += numeros[i];
    }
    
    media = (float)soma / 7;
    printf("Media: %.2f\n", media);
    
    return 0;
}

