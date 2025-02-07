#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 
typedef struct No {
    char valor;
    struct No *esquerda, *direita;
} No;

 
No* criarNo(char valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->esquerda = novoNo->direita = NULL;
    return novoNo;
}

 
No* inserir(No* raiz, char valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }
    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserir(raiz->direita, valor);
    }
    return raiz;
}

 
int buscar(No* raiz, char valor) {
    if (raiz == NULL) {
        return 0;
    }
    if (raiz->valor == valor) {
        return 1;
    }
    if (valor < raiz->valor) {
        return buscar(raiz->esquerda, valor);
    } else {
        return buscar(raiz->direita, valor);
    }
}

 
void inOrdem(No* raiz, int* primeiro) {
    if (raiz != NULL) {
        inOrdem(raiz->esquerda, primeiro);
        if (*primeiro) {
            printf("%c", raiz->valor);
            *primeiro = 0;
        } else {
            printf(" %c", raiz->valor);
        }
        inOrdem(raiz->direita, primeiro);
    }
}

void preOrdem(No* raiz, int* primeiro) {
    if (raiz != NULL) {
        if (*primeiro) {
            printf("%c", raiz->valor);
            *primeiro = 0;
        } else {
            printf(" %c", raiz->valor);
        }
        preOrdem(raiz->esquerda, primeiro);
        preOrdem(raiz->direita, primeiro);
    }
}

void posOrdem(No* raiz, int* primeiro) {
    if (raiz != NULL) {
        posOrdem(raiz->esquerda, primeiro);
        posOrdem(raiz->direita, primeiro);
        if (*primeiro) {
            printf("%c", raiz->valor);
            *primeiro = 0;
        } else {
            printf(" %c", raiz->valor);
        }
    }
}

int main() {
    No* raiz = NULL;
    char comando[10], elemento;

    while (scanf("%s", comando) != EOF) {
        if (strcmp(comando, "I") == 0) {
            scanf(" %c", &elemento);
            raiz = inserir(raiz, elemento);
        } else if (strcmp(comando, "INFIXA") == 0) {
            int primeiro = 1;
            inOrdem(raiz, &primeiro);
            printf("\n");
        } else if (strcmp(comando, "PREFIXA") == 0) {
            int primeiro = 1;
            preOrdem(raiz, &primeiro);
            printf("\n");
        } else if (strcmp(comando, "POSFIXA") == 0) {
            int primeiro = 1;
            posOrdem(raiz, &primeiro);
            printf("\n");
        } else if (strcmp(comando, "P") == 0) {
            scanf(" %c", &elemento);
            if (buscar(raiz, elemento)) {
                printf("%c existe\n", elemento);
            } else {
                printf("%c nao existe\n", elemento);
            }
        }
    }

    return 0;
}
