#include <stdio.h>

 
long long mdc(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

 
long long mmc(long long a, long long b) {
    return (a / mdc(a, b)) * b;
}

 
long long mmc3(long long a, long long b, long long c) {
    return mmc(mmc(a, b), c);
}

int main() {
    long long M, L1, L2, L3;

     
    while (scanf("%lld", &M) != EOF) {
        scanf("%lld %lld %lld", &L1, &L2, &L3);

         
        long long ciclo = mmc3(L1, L2, L3);

        
        long long proximo_alinhamento = ((M / ciclo) + 1) * ciclo;

         
        printf("%lld\n", proximo_alinhamento - M);
    }

    return 0;
}
