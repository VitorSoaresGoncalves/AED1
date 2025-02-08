#include <stdio.h>
#include <string.h>

void imprimirTriangulo(char *palavra) {
    int tam = strlen(palavra); 
    for (int i = tam; i > 0; i--) { 
        
        for (int esp = 0; esp < tam - i; esp++) {
            printf(" ");
        }
       
        for (int j = 0; j < i; j++) {
            printf("%c", palavra[j]);
            if (j < i - 1) {
                printf(" ");
            }
        }
        printf("\n"); 
    }
    printf("\n"); 
}

int main() {
    char palavra[101];  
    while (scanf("%s", palavra) != EOF) {  
        imprimirTriangulo(palavra); 
    }
    return 0;
}
