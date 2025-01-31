#include <stdio.h>

int main() {
    int P;
    scanf("%d", &P);

    int pos = 1; 
    int passos = 0;

    do {
      
        if (pos <= P / 2) {
            pos = pos * 2; 
        } else {
            pos = (pos - P / 2) * 2 - 1; 
        }
        passos++;
    } while (pos != 1);  

    printf("%d\n", passos);
    return 0;
}
