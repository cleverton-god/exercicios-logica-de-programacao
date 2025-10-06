#include <stdio.h>

int main() {
    char turno;

    printf("qual turno vc estuda? M-matutino ou V-Vespertino ou N- Noturno:\n");
    scanf(" %c", &turno);

	if (turno == 'M') {
		printf("bom dia!");
	}else if (turno == 'V') {
		printf("boa tarde!");
	}else if (turno == 'N') {
		printf("boa noite!");
	}else {
		printf("turno invalido");
	}
    
    return 0;
}

