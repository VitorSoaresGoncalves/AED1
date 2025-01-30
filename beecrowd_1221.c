#include <stdio.h>

int is_prime(int x) {
    if (x < 2) return 0;
    if (x == 2 || x == 3) return 1;
    if (x % 2 == 0) return 0;
    
    for (int i = 3; i * i <= x; i += 2) {
        if (x % i == 0) return 0;
    }
    return 1;
}

int main() {
    int N, X;
    
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &X);
        
        if (is_prime(X)) {
            printf("Prime\n");
        } else {
            printf("Not Prime\n");
        }
    }
    
    return 0;
}
