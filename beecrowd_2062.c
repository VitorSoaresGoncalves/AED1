#include <stdio.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_LENGTH 21

int main() {
    int N;
    char palavra[MAX_LENGTH];

    
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%s", palavra);

        
        if ((strncmp(palavra, "OB", 2) == 0 || strncmp(palavra, "UR", 2) == 0) && strlen(palavra) == 3) {
            palavra[2] = 'I';  
        }

        
        printf("%s", palavra);
        if (i < N - 1) {
            printf(" ");  
        }
    }

    printf("\n");
    return 0;
}
