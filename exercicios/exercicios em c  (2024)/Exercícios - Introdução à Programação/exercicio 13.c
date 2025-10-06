#include <stdio.h>

int main() {
    int numero;  

    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);  

    int sucessor = numero + 1;  
    int antecessor = numero - 1;  

    printf("O sucessor de %d = %d.\n", numero, sucessor); 
    printf("O antecessor de %d = %d.\n", numero, antecessor);  

    return 0;
}
