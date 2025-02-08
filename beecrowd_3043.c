#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int n, grafo[21][21], visitado[21], grupo[21], tamanho_grupo;

bool eh_valido(int aluno) {
    for (int i = 0; i < tamanho_grupo; i++) {
        if (grafo[grupo[i]][aluno])
            return false;
    }
    return true;
}

void encontrar_maximo(int aluno_atual) {
    if (aluno_atual > n) {
        if (tamanho_grupo > visitado[0])
            visitado[0] = tamanho_grupo;
        return;
    }

    if (eh_valido(aluno_atual)) {
        grupo[tamanho_grupo++] = aluno_atual;
        encontrar_maximo(aluno_atual + 1);
        tamanho_grupo--;
    }

    encontrar_maximo(aluno_atual + 1);
}

int main() {
    int conjunto_teste = 1;
    while (scanf("%d", &n) && n) {
        memset(grafo, 0, sizeof(grafo));
        for (int i = 1; i <= n; i++) {
            int id;
            while (scanf("%d", &id) && id) {
                grafo[i][id] = 1;
                grafo[id][i] = 1;
            }
        }
        visitado[0] = 0;
        tamanho_grupo = 0;
        encontrar_maximo(1);
        printf("Teste %d\n%d\n\n", conjunto_teste++, visitado[0]);
    }
    return 0;
}
