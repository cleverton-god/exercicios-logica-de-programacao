#include <stdio.h>

int main(){
	float massa=0;
	float aceleracao=0;
	float forca_aplicada=0;

	printf("digite a massa do objeto e aperte enter:\n");
	scanf("%f",&massa);
	printf("digite a aceleracao e aperte enter:\n");
	scanf("%f",&aceleracao);
	
	forca_aplicada=massa*aceleracao;
	
	printf("a forca aplicada e:%.2f ",forca_aplicada);



	return 0;
}
