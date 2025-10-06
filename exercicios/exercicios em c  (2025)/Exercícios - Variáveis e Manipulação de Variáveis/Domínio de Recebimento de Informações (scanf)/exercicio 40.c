#include <stdio.h>

int main(){
	float massa=0;
	float volume=0;
	float densidade=0;

	printf("digite a massa em kg e aperte enter:\n");
	scanf("%f",&massa);
	printf("digite o volume em m3 aperte enter:\n");
	scanf("%f",&volume);

	densidade=massa/volume;
	
	printf("a densidade e:%.2f",densidade);
	
	return 0;
}
