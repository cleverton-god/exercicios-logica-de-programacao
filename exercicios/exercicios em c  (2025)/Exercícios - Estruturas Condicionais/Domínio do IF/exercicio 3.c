#include <stdio.h>

int main() {
    float numero1=0;
    float numero2=0;

    printf("Digite o numero 1 e aperte enter: \n");
    scanf("%f", &numero1);
    printf("Digite o numero 2 e aperte enter: \n");
    scanf("%f", &numero2);


    if (numero1 > numero2) {
    	printf("o mumero 1 e mair que o numero 2");
	}else if (numero1 < numero2){
		printf("o mumero 2 e mair que o numero 1");
	}else{
		printf("o numero 1 e igual ao numero 2");
	}
    
    return 0;
}

