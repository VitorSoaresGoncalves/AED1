#include <stdio.h>

void processarPilha(int x) {
    int pilha[50], topo = x - 1;
    int descartadas[50], descartadasC = 0;

    for (int i = 0; i < x; i++) {
        pilha[i] = i + 1;
    }

    while (topo > 0) {
        descartadas[descartadasC++] = pilha[0];
        for (int i = 0; i < topo; i++) {
            pilha[i] = pilha[i + 1];
        }
        topo--;
        if (topo > 0) {
            int cartaM = pilha[0];
            for (int i = 0; i < topo; i++) {
                pilha[i] = pilha[i + 1];
            }
            pilha[topo] = cartaM;
        }
    }

    printf("Discarded cards:");
    if (descartadasC > 0) {
        for (int i = 0; i < descartadasC - 1; i++) {
            printf(" %d,", descartadas[i]);
        }
        printf(" %d\n", descartadas[descartadasC - 1]);
    } else {
        printf("\n");
    }

    printf("Remaining card: %d\n", pilha[0]);
}

int main() {
    int x;
    while (1) {
        scanf("%d", &x);
        if (x == 0) break;
        processarPilha(x);
    }
    return 0;
}
