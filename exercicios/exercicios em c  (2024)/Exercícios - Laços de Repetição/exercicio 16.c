#include <stdio.h>

int main() {
    int num1, num2, soma = 0;
    printf("Digite dois numeros inteiros: ");
    scanf("%d %d", &num1, &num2); 
    
    if (num1 > num2) { 
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }
    
    for (int i = num1 + 1; i < num2; i++) { 
        soma += i; 
    }
    printf("Soma dos numeros entre %d e %d: %d\n", num1, num2, soma); 
    return 0;
}

