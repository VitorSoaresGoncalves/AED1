#include <stdio.h>


int mdc(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


void simplificar(int *numerador, int *denominador) {
    int divisor = mdc(*numerador, *denominador);
    *numerador /= divisor;
    *denominador /= divisor;
    if (*denominador < 0) { 
        *numerador = -*numerador;
        *denominador = -*denominador;
    }
}

int main() {
    int N;
    scanf("%d", &N); 

    for (int i = 0; i < N; i++) {
        int n1, d1, n2, d2, nr, dr;
        char operacao;

        
        scanf("%d / %d %c %d / %d", &n1, &d1, &operacao, &n2, &d2);

        
        switch (operacao) {
            case '+':
                nr = n1 * d2 + n2 * d1;
                dr = d1 * d2;
                break;
            case '-':
                nr = n1 * d2 - n2 * d1;
                dr = d1 * d2;
                break;
            case '*':
                nr = n1 * n2;
                dr = d1 * d2;
                break;
            case '/':
                nr = n1 * d2;
                dr = n2 * d1;
                break;
            default:
                printf("Operação inválida!\n");
                continue;
        }

        
        printf("%d/%d = ", nr, dr);

        
        int num_simplificado = nr;
        int den_simplificado = dr;
        simplificar(&num_simplificado, &den_simplificado);

        
        printf("%d/%d\n", num_simplificado, den_simplificado);
    }

    return 0;
}
