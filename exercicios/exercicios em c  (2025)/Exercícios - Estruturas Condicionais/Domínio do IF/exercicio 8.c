#include <stdio.h>

int main() {
    float numero=0;

    printf("Digite um numero de 1 a 12 e saiba o mes correspondente: \n");
    scanf("%f", &numero);

    if (numero == 1) {
    	printf("o mes correspondente e janeiro");
	}else if (numero == 2){
		printf("o mes correspondente e fevereiro");
	}else if (numero == 3){
		printf("o mes correspondente e março");
	}else if (numero == 4){
		printf("o mes correspondente e abril");
	}else if (numero == 5){
		printf("o mes correspondente e maio");
	}else if (numero == 6){
		printf("o mes correspondente e junho");
	}else if (numero == 7){
		printf("o mes correspondente e julho");
	}else if (numero == 8){
		printf("o mes correspondente e agosto");
	}else if (numero == 9){
		printf("o mes correspondente e setembro");
	}else if (numero == 10){
		printf("o mes correspondente e outubro");
	}else if (numero == 11){
		printf("o mes correspondente e novembro ");
	}else if (numero == 12){
		printf("o mes correspondente e dezembro");
	}else{
		printf("numero invalido");
	}
    
    return 0;
}

