#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_CIDADES 250
#define INF INT_MAX

typedef struct {
    int destino;
    int custo;
} Aresta;

typedef struct {
    Aresta arestas[MAX_CIDADES];
    int tamanho;
} ListaAdj;

ListaAdj grafo[MAX_CIDADES];
int distancias[MAX_CIDADES];
int na_rota[MAX_CIDADES];
int N, M, C, K;

void inicializa_grafo() {
    for (int i = 0; i < MAX_CIDADES; i++) {
        grafo[i].tamanho = 0;
        distancias[i] = INF;
        na_rota[i] = 0;
    }
}

void adiciona_aresta(int origem, int destino, int custo) {
    grafo[origem].arestas[grafo[origem].tamanho].destino = destino;
    grafo[origem].arestas[grafo[origem].tamanho].custo = custo;
    grafo[origem].tamanho++;
}
void dijkstra() {
    int visitados[MAX_CIDADES] = {0};
    distancias[K] = 0;
    for (int i = 0; i < N; i++) {
        int u = -1;
        for (int j = 0; j < N; j++) {
            if (!visitados[j] && (u == -1 || distancias[j] < distancias[u])) {
                u = j;
            }
        }
        if (u == -1 || distancias[u] == INF)
            break;
        visitados[u] = 1;
 for (int j = 0; j < grafo[u].tamanho; j++) {
            int v = grafo[u].arestas[j].destino;
            int custo = grafo[u].arestas[j].custo;
            if (na_rota[u] && v == u + 1) {
                
                if (distancias[u] + custo < distancias[v]) {
                    distancias[v] = distancias[u] + custo;
                }
            } else if (!na_rota[u]) {
                
                if (distancias[u] + custo < distancias[v]) {
                    distancias[v] = distancias[u] + custo;
                }
            }
        }
    }
}
int main() {
    while (1) {
        scanf("%d %d %d %d", &N, &M, &C, &K);
        if (N == 0 && M == 0 && C == 0 && K == 0)
            break;
        inicializa_grafo();
        for (int i = 0; i < M; i++) {
            int u, v, p;
            scanf("%d %d %d", &u, &v, &p);
            adiciona_aresta(u, v, p);
            adiciona_aresta(v, u, p);
 }
        for (int i = 0; i < C; i++) {
            na_rota[i] = 1;
        }
        dijkstra();
        printf("%d\n", distancias[C - 1]);
    }
    return 0;
}
