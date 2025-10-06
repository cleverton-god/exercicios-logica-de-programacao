#include <stdio.h>

int main() {
    int numero=0;

    printf("Digite um nemoro para saber se e par ou inpar:");
    scanf("%d", &numero);

    if (numero%2 == 0) {
    	printf("o numero e par");
	}else{
		printf("o numero e inpar");
	}
    
    return 0;
}

