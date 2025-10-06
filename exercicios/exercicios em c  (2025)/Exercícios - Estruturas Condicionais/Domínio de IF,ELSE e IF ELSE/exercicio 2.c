#include <stdio.h>

int main() {
    float temperatura=0;

    printf("digite a temperatura do paciente: ");
    scanf("%f", &temperatura);
    
    if (temperatura > 37) {
    	printf("esta com febre");
	}else if (temperatura < 35){
		printf("esta com hipotermia");
	}else  {
		printf("esta normal");
	}

    return 0;
}

