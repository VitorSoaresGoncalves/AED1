#include <stdio.h>
#include <string.h>

int main() {
    char D, N[101];
    
    while (1) {
        scanf(" %c %s", &D, N);

        
        if (D == '0' && strcmp(N, "0") == 0) {
            break;
        }

        char resultado[101] = "";
        int index = 0;

         
        for (int i = 0; N[i] != '\0'; i++) {
            if (N[i] != D) {
                resultado[index++] = N[i];
            }
        }
        resultado[index] = '\0';

         
        int inicio = 0;
        while (resultado[inicio] == '0') {
            inicio++;
        }

       
        if (resultado[inicio] == '\0') {
            printf("0\n");
        } else {
            printf("%s\n", resultado + inicio);
        }
    }

    return 0;
}
