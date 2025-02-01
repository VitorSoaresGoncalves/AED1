#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000
#define MAX_LEN 100

 
int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

 
int prefixo(char *a, char *b) {
    return strncmp(a, b, strlen(a)) == 0;
}

int main() {
    int N;
    char *palavras[MAX_N];

    while (scanf("%d", &N), N != 0) {
        for (int i = 0; i < N; i++) {
            palavras[i] = (char *)malloc((MAX_LEN + 1) * sizeof(char));
            scanf("%s",palavras[i]);
        }

      
        qsort(palavras, N, sizeof(char *), compare);

       
        int ruim = 0;
        for (int i = 0; i < N - 1; i++) {
            if (prefixo(palavras[i], palavras[i + 1])) {
                ruim = 1;
                break;
            }
        }

       if (ruim) {
            printf("Conjunto Ruim\n");
        } else {
            printf("Conjunto Bom\n");
        }

         
        for (int i = 0; i < N; i++) {
            free(palavras[i]);
        }
    }

    return 0;
}
