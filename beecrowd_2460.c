#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int posicao;
    struct lista *prox;
} lista;

// Cria um novo nó na lista
lista* addnumero(int posicao) {
    lista* novonumero = (lista*) malloc(sizeof(lista));
    novonumero->posicao = posicao;
    novonumero->prox = NULL;
    return novonumero;
}

// Adiciona um novo elemento ao final da lista
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

// Remove um elemento específico da lista
void remover(lista** cabeca, int posicao) {
    lista* atual = *cabeca;
    lista* anterior = NULL;

    while (atual != NULL) {
        if (atual->posicao == posicao) {
            if (anterior == NULL) {
                *cabeca = atual->prox; // Remove o primeiro elemento
            } else {
                anterior->prox = atual->prox; // Remove no meio ou no final
            }
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
}

// Imprime a lista atual
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

    // Leitura do número de pessoas na fila inicial
    scanf("%d", &N);
    lista* cabeca = NULL;

    // Criação da fila inicial
    for (int i = 0; i < N; i++) {
        int id;
        scanf("%d", &id);
        checar(&cabeca, id);
    }

    // Leitura do número de pessoas que saíram da fila
    scanf("%d", &M);

    // Processamento de remoção
    for (int i = 0; i < M; i++) {
        int id;
        scanf("%d", &id);
        remover(&cabeca, id); // Remove cada pessoa que saiu da fila
    }

    // Imprime a lista final
    print_list(cabeca);

    // Libera a memória restante
    while (cabeca != NULL) {
        lista* temp = cabeca;
        cabeca = cabeca->prox;
        free(temp);
    }

    return 0;
}
