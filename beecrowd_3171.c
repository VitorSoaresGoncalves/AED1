#include <stdio.h>
#include <stdlib.h>



int grafo[100][100];
int visitado[100];


void dfs(int led, int n) {
    visitado[led] = 1; 
    for (int i = 1; i <= n; i++) {
        if (grafo[led][i] && !visitado[i]) {
            dfs(i, n);
        }
    }
}

int main() {
    int n, l; 
    scanf("%d %d", &n, &l);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            grafo[i][j] = 0;
        }
        visitado[i] = 0;
    }

   
    for (int i = 0; i < l; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        grafo[x][y] = 1; 
        grafo[y][x] = 1; 
    }

    dfs(1, n);

    
    int completo = 1;
    for (int i = 1; i <= n; i++) {
        if (!visitado[i]) {
            completo = 0;
            break;
        }
    }

    
    if (completo) {
        printf("COMPLETO\n");
    } else {
        printf("INCOMPLETO\n");
    }

    return 0;
}
