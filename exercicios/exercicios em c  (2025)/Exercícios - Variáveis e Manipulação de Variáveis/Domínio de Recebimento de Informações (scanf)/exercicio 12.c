#include <stdio.h>

int main() {
	float numero1=0,numero2,numero3,numero4;
	float media=0;
	
	printf("digite quatro numeros\n");
	scanf("%f %f %f %f",&numero1,&numero2,&numero3,&numero4);
	
	media=(numero1+numero2+numero3+numero4)/4;

	printf("a media dos numeros e:%.2f\n",media);


    return 0;
}

