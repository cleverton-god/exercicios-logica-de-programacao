#include <stdio.h>

int main() {
	float base=0;
	float altura=0;
	float area=0;
	
	printf("digite a base\n");
	scanf("%f",&base);
	printf("digite a altura\n");
	scanf("%f",&altura);
	
	area=(base*altura)/2;
	
	
	printf("a area e:%.2f",area);
	
    return 0;
}

