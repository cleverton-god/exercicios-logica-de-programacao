#include <stdio.h>

int main() {
    float numero=0;
    float resultado=0;
    

    printf("Digite um numero:\n");
    scanf("%f", &numero);

    if (numero >= 0) {
    	resultado= numero * numero;
    	printf("numero ao quadrado: %.2f",resultado);
	}else{
		printf("numero e invalido");
	}
    
    return 0;
}

