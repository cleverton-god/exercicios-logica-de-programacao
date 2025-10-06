#include <stdio.h>
#include <math.h>

int main() {
    float cateto1, cateto2;
    
    printf("Digite o comprimento do primeiro cateto: ");
    scanf("%f", &cateto1);
    printf("Digite o comprimento do segundo cateto: ");
    scanf("%f", &cateto2);
    
    float hipotenusa = sqrt((cateto1 * cateto1) + (cateto2 * cateto2));
    printf("A hipotenusa e: %.2f\n", hipotenusa);
    
    return 0;
}

