#include <stdio.h>

int main() {
	int numero=0;
	int sucessor=0;
	int antecessor=0;
	
	printf("digite um numero inteiro\n");
	scanf("%i",&numero);
	
	sucessor=numero+1;
	antecessor=numero-1;

	printf("a sucessor do numero e:%i\n",sucessor);
	printf("a antecessor do numero e:%i\n",antecessor);
    return 0;
}

