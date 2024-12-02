#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 400000

void merge(int V[], int esquerda, int meio, int direita) {
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) {
        L[i] = V[esquerda + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = V[meio + 1 + j];
    }

    int i = 0, j = 0, k = esquerda;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            V[k] = L[i];
            i++;
        } else {
            V[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        V[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        V[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(int V[], int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        mergeSort(V, esquerda, meio);
        mergeSort(V, meio + 1, direita);
        merge(V, esquerda, meio, direita);
    }
}

int main() {
    int V[MAX];

    for (int n = 0; n <= MAX; n += 50000) {
        for (int i = 0; i < n; i++) {
            V[i] = rand() % 1000000;
        }

        clock_t comeco = tempo();
        mergeSort(V, 0, n - 1);
        clock_t fim = tempo();

        double demorou = ((double)(fim - comeco)) / CLOCKS_PER_SEC;

        printf("N = %d, Tempo = %f segundos\n", n, demorou);
    }

    return 0;
}


