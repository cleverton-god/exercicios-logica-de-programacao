#include <stdio.h>
#include <string.h>

int main() {
    char str1[20] = "Ola, ";
    char str2[] = "Mundo!";
    
    strcat(str1, str2);
    
    printf("%s\n", str1);
    return 0;
}

