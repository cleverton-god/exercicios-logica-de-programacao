#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    int matriz[5][5];
    srand(time(0)); 

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            matriz[i][j] = rand() % 100; 
            if(i == j) {
                printf("%d ", matriz[i][j]); 
            }
        }
    }
    printf("\n");
    return 0;
}
