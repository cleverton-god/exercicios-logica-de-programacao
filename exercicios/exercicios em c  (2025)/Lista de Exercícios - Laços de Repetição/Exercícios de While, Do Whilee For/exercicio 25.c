#include <stdio.h>

int main() {
    int n;
	int numero;
	int menor;
	int maior;
	int soma=0;
	
    printf("Quantos numeros deseja inserir? ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Quantidade invalida!\n");
        return 1;
    }

    printf("Digite um numero: ");
    scanf("%d", &numero);
    menor = maior = soma = numero;

    for (int i = 1; i < n; i++) {
        printf("Digite outro numero: ");
        scanf("%d", &numero);

        soma += numero;
        if (numero < menor) menor = numero;
        if (numero > maior) maior = numero;
    }

    printf("Menor numero: %d\n", menor);
    printf("Maior numero: %d\n", maior);
    printf("Soma dos numeros: %d\n", soma);
    return 0;
}

