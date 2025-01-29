#include <stdio.h>
#include <stdlib.h>
typedef struct no {
    int key;
    struct no* prox;
} no;
no* criar(int key) {
    no* novoNo = (no*)malloc(sizeof(no));
    if (novoNo != NULL) {
        novoNo->key = key;
        novoNo->prox = NULL;
    }
    return novoNo;
}
void inserir(no* hash[], int key, int M) {
    int onde = key % M;
    no* novoNo = criar(key);
    if (novoNo == NULL) return;
    if (hash[onde] == NULL) {
        hash[onde] = novoNo;
    } else {
        no* atual = hash[onde];
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novoNo;
    }
}
void printHashTable(no* hash[], int M) {
    for (int i = 0; i < M; i++) {
        printf("%d ->", i);
        no* atual = hash[i];
        while (atual != NULL) {
            printf(" %d ->", atual->key);
            atual = atual->prox;
        }
        printf(" \\\n");
    }
}
void freeHashTable(no* hash[], int M) {
    for (int i = 0; i < M; i++) {
        no* current = hash[i];
        while (current != NULL) {
            no* temp = current;
            current = current->prox;
            free(temp);
        }
        hash[i] = NULL;
    }
}
int main() {
    int N;
    scanf("%d", &N);
    for (int caso = 0; caso < N; caso++) {
        int M, C;
        scanf("%d %d", &M, &C);
        no** hash = (no**)malloc(M * sizeof(no*));
        for (int i = 0; i < M; i++) {
            hash[i] = NULL;
        }
        for (int i = 0; i < C; i++) {
            int key;
            scanf("%d", &key);
            inserir(hash, key, M);
        }
        printHashTable(hash, M);
        freeHashTable(hash, M);
        free(hash);
        if (caso < N - 1) {
            printf("\n");
        }
    }
    return 0;
}
