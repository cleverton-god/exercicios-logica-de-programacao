#include <stdio.h>

int main() {
	float numero=0;
	
	printf("digite um numero\n");
	scanf("%f",& numero);
	numero=numero*2;
	printf("o dobro desse numero e:%.2f",numero);
    return 0;
}

