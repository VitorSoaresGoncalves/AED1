#include <stdio.h>

int main() {
    int N, X;
    scanf("%d", &N);

    while (N--) {
        scanf("%d", &X);

        
        unsigned long long graos = 1;

       
        unsigned long long total_graos = graos;
        for (int i = 1; i < X; i++) {
            graos *= 2;         
            total_graos += graos; 
        }

        
        unsigned long long gramas = total_graos / 12;

       
        unsigned long long kg = gramas / 1000;

        printf("%llu kg\n", kg);
    }

    return 0;
}
