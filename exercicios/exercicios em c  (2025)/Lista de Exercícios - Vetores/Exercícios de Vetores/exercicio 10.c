#include <stdio.h>

int main() {
    int numeros[10] = {1, 3, 3, 5, 7, 3, 9, 3, 11, 13};
    int numero;
	int contagem = 0;
    
    printf("Digite um numero para contar: ");
    scanf("%d", &numero);
    
    for (int i = 0; i < 10; i++) {
        if (numeros[i] == numero) {
            contagem++;
        }
    }
    
    printf("O numero %d aparece %d vezes\n", numero, contagem);
    
    return 0;
}

