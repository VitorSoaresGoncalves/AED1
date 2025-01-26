#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int compare(const void *a, const void *b) {
    const char *str1 = *(const char **)a;
    const char *str2 = *(const char **)b;
    int tam1 = strlen(str1);
    int tam2 = strlen(str2);

    if (tam1 != tam2) {
        return tam2 - tam1; 
    }
    return 0; 
}

int main() {
    int n;
    scanf("%d", &n); 
    getchar(); 

    for (int i = 0; i < n; i++) {
        char input[1001];
        fgets(input, 1001, stdin); 
        input[strcspn(input, "\n")] = '\0'; 

        char *palavras[50]; 
        int contar = 0;

        char *add = strtok(input, " ");
        while (add != NULL) {
            palavras[contar++] = add;
            add = strtok(NULL, " ");
        }

    
        qsort(palavras, contar, sizeof(char *), compare);

       
        for (int j = 0; j < contar; j++) {
            printf("%s", palavras[j]);
            if (j < contar - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
