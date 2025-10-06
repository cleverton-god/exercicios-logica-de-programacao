#include <stdio.h>

int main() {
    float numero=0;

    printf("Digite um numero e aperte enter: \n");
    scanf("%f", &numero);

    if (numero >= 0) {
    	printf("o numero %.2f e positivo",numero);
	}else{
		printf("o numero %.2f e negativo",numero);
	}
    
    return 0;
}

