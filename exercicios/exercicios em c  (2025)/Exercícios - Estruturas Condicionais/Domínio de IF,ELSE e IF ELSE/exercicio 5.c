#include <stdio.h>

int main() {
	char operador;
	float numero1=0;
	float numero2=0;
	float resultado=0;
	
	printf("digite o aoperador para calcular 2 numeros entre +, -, *, / : \n");
	scanf("%c", &operador);
	printf("digite o numero 1:\n");
	scanf ("%f", &numero1);
	printf("digite o numero 2:\n");
	scanf ("%f", &numero2);
	
	if (operador == '+'){
		resultado=numero1+numero2;
	}else if (operador == '-'){
		resultado=numero1-numero2;
	}else if (operador == '*'){
		resultado=numero1*numero2;
	}else if (operador == '/'){
		resultado=numero1/numero2;
	}else {
		printf("operador invalido!");
		return 1;
	}
	printf("o resultado e:%.2f",resultado);
    return 0;
}

