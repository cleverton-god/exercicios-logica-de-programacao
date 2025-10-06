#include <stdio.h>

int main() {
    float numero=0;

    printf("Digite um numero de 1 a 7 e saiba o dia da semana correspondente: \n");
    scanf("%f", &numero);

    if (numero == 1) {
    	printf("o dia correspondente e domigo");
	}else if (numero == 2){
		printf("o dia correspondente e segunda");
	}else if (numero == 3){
		printf("o dia correspondente e terca");
	}else if (numero == 4){
		printf("o dia correspondente e quarta");
	}else if (numero == 5){
		printf("o dia correspondente e quinta");
	}else if (numero == 6){
		printf("o dia correspondente e sexta");
	}else if (numero == 7){
		printf("o dia correspondente e sabado");
	}else{
		printf("numero invalido");
	}
    
    return 0;
}

