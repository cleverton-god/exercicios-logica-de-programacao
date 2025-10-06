#include <stdio.h>

int main() {
    float nota=0;

    printf("digite a nota do estudante de 1 a 10: ");
    scanf("%f", &nota);
    
    if (nota >= 7) {
    	printf("aluno aprovado");
	}else if (nota >= 5 && nota < 7){
		printf("aluno em recuperacao");
	}else if (nota < 5) {
		printf("aluno reprovado");
	}

    return 0;
}

