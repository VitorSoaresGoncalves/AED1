#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_NOMES 1000
#define MAX_TAM 201   

 
int comparar(const void *a, const void *b) {
    return strcasecmp(*(const char **)a, *(const char **)b);
}

int main() {
    char *nomes[MAX_NOMES];
    char buffer[MAX_TAM];
    int qtd = 0;

     
    while (fgets(buffer, MAX_TAM, stdin)) {
        
        buffer[strcspn(buffer, "\n")] = 0;

       
        nomes[qtd] = malloc(strlen(buffer) + 1);
        if (nomes[qtd] == NULL) {
            fprintf(stderr, "Erro de alocação de memória\n");
            return 1;
        }

        strcpy(nomes[qtd], buffer);
        qtd++;

 
        if (qtd >= MAX_NOMES) break;
    }

    if (qtd == 0) {
        fprintf(stderr, "Nenhum nome foi fornecido.\n");
        return 1;
    }

     
    qsort(nomes, qtd, sizeof(char *), comparar);

     
    printf("%s\n", nomes[qtd - 1]);

    
    for (int i = 0; i < qtd; i++) {
        free(nomes[i]);
    }

    return 0;
}
