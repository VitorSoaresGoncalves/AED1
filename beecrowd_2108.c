#include <stdio.h>
#include <string.h>

#define MAX_LEN 101

int main() {
    char linha[MAX_LEN];
    char maior[MAX_LEN] = "";
    int Tmax = 0;
    int plinha = 1;  

    while (1) {
        if (!fgets(linha, sizeof(linha), stdin)) break;
        linha[strcspn(linha, "\n")] = '\0'; 
        
        if (strcmp(linha, "0") == 0) break;

        char *token = strtok(linha, " ");
        int primeiro = 1;

        while (token != NULL) {
            if (!primeiro) printf("-");
            printf("%ld", strlen(token));

            
            if ((int)strlen(token) >= Tmax) {
                Tmax = strlen(token);
                strcpy(maior, token);
            }

            primeiro = 0;
            token = strtok(NULL, " ");
        }

        printf("\n");
    }

    printf("\nThe biggest word: %s\n", maior);
    return 0;
}
