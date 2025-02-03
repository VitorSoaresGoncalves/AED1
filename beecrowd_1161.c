#include <stdio.h>

 
unsigned long long fatorial(int n) {
    unsigned long long resultado = 1;
    for (int i = 2; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

int main() {
    int m, n;
 
    while (scanf("%d %d", &m, &n) != EOF) {
         
        unsigned long long soma = fatorial(m) + fatorial(n);
        printf("%llu\n", soma);
    }

    return 0;
}
