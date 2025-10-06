#include <stdio.h>

int main() {
	float numero1=0,numero2,numero3;
	float media=0;
	float soma=0;
	
	printf("digite tres numeros\n");
	scanf("%f %f %f",&numero1,&numero2,&numero3);
	
	media=(numero1+numero2+numero3)/3;
	soma=numero1+numero2+numero3;

	printf("a media dos numeros e:%.2f\n",media);
	printf("a soma dos numeros e:%.2f\n",soma);

    return 0;
}

