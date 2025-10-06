#include <stdio.h>

int main() {
    int idades[6];
	int soma = 0;
    float media=0;
    
    for (int i = 0; i < 6; i++) {
        printf("Digite a idade: ");
        scanf("%d", &idades[i]);
        soma += idades[i];
    }
    
    media = (float)soma / 6;
    printf("Idade media: %.2f\n", media);
    
    return 0;
}

