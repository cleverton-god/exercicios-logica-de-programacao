#include <stdio.h>

int main() {
    int num1, num2, num3, num4;
    printf("Digite quatro numeros inteiros: ");
    scanf("%d %d %d %d", &num1, &num2, &num3, &num4);
    
    float media = (num1 + num2 + num3 + num4) / 4.0;
    printf("A media aritmetica e: %.2f\n", media);
    
    return 0;
}

