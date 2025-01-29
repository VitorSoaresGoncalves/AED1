#include <stdio.h>
#include <stdlib.h>

typedef struct Aresta {
    int u, v, peso;
} Aresta;

typedef struct encontraUniao {
    int *pai, *rank;
    int n;
} encontraUniao;

encontraUniao* criar_union_find(int n) {
    encontraUniao* uniao = (encontraUniao*)malloc(sizeof(encontraUniao));
    uniao->n = n;
    uniao->pai = (int*)malloc(n * sizeof(int));
    uniao->rank = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        uniao->pai[i] = i;
        uniao->rank[i] = 0;
    }
    return uniao;
}
int achar(encontraUniao* uniao, int x) {
    if (uniao->pai[x] != x) {
        uniao->pai[x] = achar(uniao, uniao->pai[x]); 
    }
    return uniao->pai[x];
}

void uni(encontraUniao* uniao, int x, int y) {
    int raizX = achar(uniao, x);
    int raizY = achar(uniao, y);
    if (raizX != raizY) {
        if (uniao->rank[raizX] > uniao->rank[raizY]) {
            uniao->pai[raizY] = raizX;
        } else if (uniao->rank[raizX] < uniao->rank[raizY]) {
            uniao->pai[raizX] = raizY;
        } else {
            uniao->pai[raizY] = raizX;
            uniao->rank[raizX]++;
        }
    }
}
int comparar(const void *a, const void *b) {
    return ((Aresta*)a)->peso - ((Aresta*)b)->peso;
}
long long kruskal(Aresta* arestas, int m, int n) {
    encontraUniao* uniao = criar_union_find(m);
    qsort(arestas, n, sizeof(Aresta), comparar);
    long long custo_mst = 0;
    int arestas_usadas = 0;
    for (int i = 0; i < n && arestas_usadas < m - 1; i++) {
        Aresta a = arestas[i];
        if (achar(uniao, a.u) != achar(uniao, a.v)) {
            uni(uniao, a.u, a.v);
            custo_mst += a.peso;
            arestas_usadas++;
        }
    }
    free(uniao->pai);
    free(uniao->rank);
    free(uniao);
    return custo_mst;
}

int main() {
    int m, n;
    while (1) {
        scanf("%d %d", &m, &n);
        if (m == 0 && n == 0) 
            break;
        Aresta* arestas = (Aresta*)malloc(n * sizeof(Aresta));
        long long custo_total = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &arestas[i].u, &arestas[i].v, &arestas[i].peso);
            custo_total += arestas[i].peso;
        }
        long long custo_mst = kruskal(arestas, m, n);
        printf("%lld\n", custo_total - custo_mst);
        free(arestas);
    }
    return 0;
}
