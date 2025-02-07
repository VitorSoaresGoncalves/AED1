#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esquerda, *direita;
} No;

 
No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->esquerda = novoNo->direita = NULL;
    return novoNo;
}

 
No* inserir(No* raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }
    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else {
        raiz->direita = inserir(raiz->direita, valor);
    }
    return raiz;
}


void preOrdem(No* raiz, int* primeiro) {
    if (raiz != NULL) {
        if (*primeiro) {
            printf("%d", raiz->valor);
            *primeiro = 0;
        } else {
            printf(" %d", raiz->valor);
        }
        preOrdem(raiz->esquerda, primeiro);
        preOrdem(raiz->direita, primeiro);
    }
}

void inOrdem(No* raiz, int* primeiro) {
    if (raiz != NULL) {
        inOrdem(raiz->esquerda, primeiro);
        if (*primeiro) {
            printf("%d", raiz->valor);
            *primeiro = 0;
        } else {
            printf(" %d", raiz->valor);
        }
        inOrdem(raiz->direita, primeiro);
    }
}

void posOrdem(No* raiz, int* primeiro) {
    if (raiz != NULL) {
        posOrdem(raiz->esquerda, primeiro);
        posOrdem(raiz->direita, primeiro);
        if (*primeiro) {
            printf("%d", raiz->valor);
            *primeiro = 0;
        } else {
            printf(" %d", raiz->valor);
        }
    }
}

 
int main() {
    int casos, n, valor;
    scanf("%d", &casos);

    for (int i = 1; i <= casos; i++) {
        scanf("%d", &n);

        No* raiz = NULL;
        for (int j = 0; j < n; j++) {
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
        }

        printf("Case %d:\n", i);

        int primeiro = 1;
        printf("Pre.: ");
        preOrdem(raiz, &primeiro);
        printf("\n");

        primeiro = 1;
        printf("In..: ");
        inOrdem(raiz, &primeiro);
        printf("\n");

        primeiro = 1;
        printf("Post: ");
        posOrdem(raiz, &primeiro);
        printf("\n\n");
    }

    return 0;
}
