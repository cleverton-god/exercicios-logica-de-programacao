#include <stdio.h>

int main() {
    int idade=0;

    printf("Digite a idade: ");
    scanf("%d", &idade);

    if (idade >= 18) {
    	printf("voce e maior de idade");
	}else{
		printf("voce e menor de idade");
	}
    
    return 0;
}

