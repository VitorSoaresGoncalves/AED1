#include <stdio.h>
#include <math.h>

#define EPSILON 1e-9  

 
int iguais(double a, double b) {
    return fabs(a - b) < EPSILON;
}

 
int verificarEquilibrio(double pesos[]) {
    
    for (int i = 0; i < (1 << 4); i++) {
        double lado1 = 0, lado2 = 0;

         
        for (int j = 0; j < 4; j++) {
            if (i & (1 << j)) {
                lado1 += pesos[j];  
            } else {
                lado2 += pesos[j];  
            }
        }

         
        if (iguais(lado1, lado2)) {
            return 1;  
        }
    }

    return 0; 
}

int main() {
    double pesos[4];

     
    for (int i = 0; i < 4; i++) {
        scanf("%lf", &pesos[i]);
    }

     
    if (verificarEquilibrio(pesos)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
