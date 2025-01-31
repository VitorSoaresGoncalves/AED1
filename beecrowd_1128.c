#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 2000

typedef struct No {
    int vertice;
    struct No* prox;
} No;

typedef struct Grafo {
    int vertices;
    No* listaAdj[MAX];
    No* listaReversa[MAX];
} Grafo;

No* criarNo(int v) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->vertice = v;
    novoNo->prox = NULL;
    return novoNo;
}

Grafo* criarGrafo(int vertices) {
    Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
    grafo->vertices = vertices;
    
    for (int i = 0; i < vertices; i++) {
        grafo->listaAdj[i] = NULL;
        grafo->listaReversa[i] = NULL;
    }
    return grafo;
}

void adicionarAresta(Grafo* grafo, int origem, int destino, int tipo) {
    No* novoNo = criarNo(destino);
    novoNo->prox = grafo->listaAdj[origem];
    grafo->listaAdj[origem] = novoNo;

    No* noReverso = criarNo(origem);
    noReverso->prox = grafo->listaReversa[destino];
    grafo->listaReversa[destino] = noReverso;

    if (tipo == 2) {
        novoNo = criarNo(origem);
        novoNo->prox = grafo->listaAdj[destino];
        grafo->listaAdj[destino] = novoNo;

        noReverso = criarNo(destino);
        noReverso->prox = grafo->listaReversa[origem];
        grafo->listaReversa[origem] = noReverso;
    }
}

void dfs(No* lista[], int vertice, int visitado[]) {
    visitado[vertice] = 1;
    No* temp = lista[vertice];
    while (temp) {
        if (!visitado[temp->vertice]) {
            dfs(lista, temp->vertice, visitado);
        }
        temp = temp->prox;
    }
}

int verificarConectividade(Grafo* grafo) {
    int visitado[MAX] = {0};

    dfs(grafo->listaAdj, 0, visitado);
    for (int i = 0; i < grafo->vertices; i++) {
        if (!visitado[i]) return 0;
    }

    memset(visitado, 0, sizeof(visitado));
    dfs(grafo->listaReversa, 0, visitado);
    for (int i = 0; i < grafo->vertices; i++) {
        if (!visitado[i]) return 0;
    }

    return 1;
}

int main() {
    int N, M;
    while (scanf("%d %d", &N, &M) && (N != 0 && M != 0)) {
        Grafo* grafo = criarGrafo(N);

        for (int i = 0; i < M; i++) {
            int V, W, P;
            scanf("%d %d %d", &V, &W, &P);
            adicionarAresta(grafo, V - 1, W - 1, P);
        }

        printf("%d\n", verificarConectividade(grafo));

        free(grafo);
    }

    return 0;
}
