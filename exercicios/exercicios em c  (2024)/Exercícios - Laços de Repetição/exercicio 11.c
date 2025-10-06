#include <stdio.h>

int main() {
    int n;
    printf("Digite a quantidade de numeros: ");
    scanf("%d", &n); 
    int menor, maior, soma = 0; 
    for (int i = 0; i < n; i++) { 
        int num; 
        printf("Digite um numero: ");
        scanf("%d", &num); 
        
        if (i == 0) { 
            menor = maior = num; 
        } else {
            if (num < menor) menor = num; 
            if (num > maior) maior = num; 
        }
        soma += num; 
    }
    printf("Menor: %d, Maior: %d, Soma: %d\n", menor, maior, soma); 
    return 0;
}

