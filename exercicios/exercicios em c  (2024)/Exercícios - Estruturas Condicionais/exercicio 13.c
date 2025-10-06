#include <stdio.h>

int main() {
    float num1, num2;
    char operador;
    printf("Digite dois numeros:\n");
    scanf("%f %f", &num1, &num2);
    printf("Digite o operador (+, -, *, /):\n ");
    scanf(" %c", &operador);
    
    switch (operador) {
        case '+': printf("Resultado: %.2f\n", num1 + num2); break;
        case '-': printf("Resultado: %.2f\n", num1 - num2); break;
        case '*': printf("Resultado: %.2f\n", num1 * num2); break;
        case '/':
            if (num2 != 0) {
                printf("Resultado: %.2f\n", num1 / num2);
            } else {
                printf("Divisao por zero nao e permitido\n");
            }
            break;
        default: printf("Operador invalido\n");
    }

    return 0;
}

