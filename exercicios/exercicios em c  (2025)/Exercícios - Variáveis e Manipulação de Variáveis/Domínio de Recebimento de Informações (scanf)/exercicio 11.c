#include <stdio.h>

int main() {
	float numero1=0;
	float numero2=0;
	float media=0;
	
	printf("digite dois numeros\n");
	scanf("%f %f",&numero1,&numero2);
	
	media=(numero1+numero2)/2;

	printf("a media dos numeros e:%.2f\n",media);


    return 0;
}

