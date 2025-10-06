#include <stdio.h>
#include <string.h>
void login(){
	char usuario[50],senha[10];
	
	printf("usuario:");
	fgets(usuario, sizeof(usuario), stdin);
	printf("senha:");
	scanf("%s", &senha);
	
	if(strcmp(senha, "1234")==0){
		printf("acesso permitido para:%s \n",usuario);
	}else {
		printf("senha incorreta\n");
	}
}
int main(){
	login();
	return 0;
}
