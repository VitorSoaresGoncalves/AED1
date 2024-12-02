#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 400000 


void insertionSort(int V[], int n) {
    for (int i = 1; i < n; i++) {
        int key = V[i];
        int j = i - 1;

        
        while (j >= 0 && V[j] > key) {
            V[j + 1] = V[j];
            j = j - 1;
        }
        V[j + 1] = key;
    }
}


int main() {
    int V[MAX]; 

    for (int n = 0; n <= MAX; n += 50000) {
        
        for (int i = 0; i < n; i++) {
            V[i] = rand() % 1000000;
        }

        
        clock_t comeco = clock();
        insertionSort(V, n);
        clock_t fim = clock();

        double demorou = ((double)(fim - comeco)) / CLOCKS_PER_SEC;

        printf("N = %d, Tempo = %f segundos\n", n, demorou);
    }

    return 0;
}
