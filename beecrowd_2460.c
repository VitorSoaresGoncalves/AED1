#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int posicao;
    struct lista *prox;
} lista;


lista* addnumero(int posicao) {
    lista* novonumero = (lista*) malloc(sizeof(lista));
    novonumero->posicao = posicao;
    novonumero->prox = NULL;
    return novonumero;
}


void checar(lista** cabeca, int posicao) {
    lista* novonumero = addnumero(posicao);
    if (*cabeca == NULL) {
        *cabeca = novonumero;
        return;
    }
    lista* atual = *cabeca;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }
    atual->prox = novonumero;
}


void remover(lista** cabeca, int posicao) {
    lista* atual = *cabeca;
    lista* anterior = NULL;

    while (atual != NULL) {
        if (atual->posicao == posicao) {
            if (anterior == NULL) {
                *cabeca = atual->prox; 
            } else {
                anterior->prox = atual->prox;
            }
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
}


void print_list(lista* cabeca) {
    lista* temp = cabeca;
    while (temp != NULL) {
        printf("%d ", temp->posicao);
        temp = temp->prox;
    }
    printf("\n");
}

int main() {
    int N, M;

    
    scanf("%d", &N);
    lista* cabeca = NULL;

    
    for (int i = 0; i < N; i++) {
        int id;
        scanf("%d", &id);
        checar(&cabeca, id);
    }

    
    scanf("%d", &M);

    
    for (int i = 0; i < M; i++) {
        int id;
        scanf("%d", &id);
        remover(&cabeca, id); 
    }

    
    print_list(cabeca);

    
    while (cabeca != NULL) {
        lista* temp = cabeca;
        cabeca = cabeca->prox;
        free(temp);
    }

    return 0;
}
