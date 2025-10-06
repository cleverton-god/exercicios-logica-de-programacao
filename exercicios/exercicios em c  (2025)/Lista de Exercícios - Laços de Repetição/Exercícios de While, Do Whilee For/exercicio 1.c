#include <stdio.h>

int main() {
	int contador=0;
	
	while (contador<=20) {
		printf("%d\n",contador);
		contador++;
	}
	contador=0;
	while (contador<=20) {
		printf("%d\t",contador);
		contador++;
	}
	return 0;
}
