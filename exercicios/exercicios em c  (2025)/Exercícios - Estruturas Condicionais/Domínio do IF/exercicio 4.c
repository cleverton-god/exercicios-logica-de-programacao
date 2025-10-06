#include <stdio.h>

int main() {
    char sexo;

    printf("Digite uma letra (M/F): ");
    scanf(" %c", &sexo);

	if (sexo != 'm' && sexo != 'f') {
        printf("Sexo invalido.\n");
        return 1;
    }
    if (sexo == 'm') {
    	printf("m = masculino");
	}else if (sexo == 'f'){
		printf("f = feminino");
	}else{
		printf("letra invalida");
	}
    
    return 0;
}

