#include <stdio.h>

int main() {
    float numero1=0;
    float numero2=0;
	
    printf("Digite dois numeros e saiba qual e o maior ou se sao iguais:\n");
    scanf("%f %f", &numero1,&numero2);

    if (numero1 == numero2) {
    	printf("Numeros Iguais");
	}else if (numero1 > numero2){
		printf("numero 1:%.2f e o maior que o numero 2:%.2f \n",numero1,numero2);
	}else {
		printf("o numero 2:%.2f e maior que o numero 1:%.2f",numero2,numero1);
	}
    return 0;
}

