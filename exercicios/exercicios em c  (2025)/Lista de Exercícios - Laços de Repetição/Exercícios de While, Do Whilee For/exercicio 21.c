#include <stdio.h>

int main() {
	int numero=0;
	while (1) {
		printf("digite um uma nota entre 0 e 10:  ");
		scanf("%d", &numero);
		if (numero >= 0 && numero <= 10) {
			break;
		}else {
			printf("nota invalido\n");
		}
	}
	
	
	return 0;
}
