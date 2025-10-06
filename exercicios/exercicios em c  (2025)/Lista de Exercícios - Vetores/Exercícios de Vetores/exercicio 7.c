#include <stdio.h>

int main() {
    int numeros[10] = {12, 34, 7, 89, 23, 5, 56, 78, 91, 4};
    int maior = numeros[0], menor = numeros[0];
    
    for (int i = 1; i < 10; i++) {
        if (numeros[i] > maior) {
		maior = numeros[i];
		}
        if (numeros[i] < menor) {
		menor = numeros[i];
    	}
    }
    
    printf("Maior: %d\n", maior);
    printf("Menor: %d\n", menor);
    
    return 0;
}
