#include <stdio.h>
#include <string.h>

#define MAX_TAM 1000

void corrigirTexto(char *texto) {
    int i, j = 0;
    int tamanho = strlen(texto);
    char resultado[MAX_TAM];

    for (i = 0; i < tamanho; i++) {
        
        if (texto[i] == ' ' && (texto[i + 1] == ',' || texto[i + 1] == '.')) {
            continue;
        }
        resultado[j++] = texto[i];
    }
    resultado[j] = '\0';

    
    strcpy(texto, resultado);
}

int main() {
    char linha[MAX_TAM];

     
    while (fgets(linha, MAX_TAM, stdin)) {
       
        linha[strcspn(linha, "\n")] = 0;

        corrigirTexto(linha);

         
        printf("%s\n", linha);
    }

    return 0;
}
