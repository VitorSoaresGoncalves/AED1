#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 5
#define MAX_TESTES 400

typedef struct {
    int x, y, passos;
} No;

int direcoes[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int bfs(int matriz[TAMANHO][TAMANHO], int xInicial, int yInicial, int xFinal, int yFinal) {
    int visitado[TAMANHO][TAMANHO] = {0};
    No fila[TAMANHO * TAMANHO];
    int frente = 0, tras = 0;

    fila[tras++] = (No){xInicial, yInicial, 0};
    visitado[xInicial][yInicial] = 1;

    while (frente < tras) {
        No atual = fila[frente++];
        
        if (atual.x == xFinal && atual.y == yFinal)
            return 1;

        for (int i = 0; i < 4; i++) {
            int novoX = atual.x + direcoes[i][0];
            int novoY = atual.y + direcoes[i][1];

            if (novoX >= 0 && novoX < TAMANHO && novoY >= 0 && novoY < TAMANHO &&
                matriz[novoX][novoY] == 0 && !visitado[novoX][novoY]) {
                fila[tras++] = (No){novoX, novoY, atual.passos + 1};
                visitado[novoX][novoY] = 1;
            }
        }
    }
    return 0;
}

void resolver(int matriz[TAMANHO][TAMANHO]) {
    int inicioX = 0, inicioY = 0;
    int destinoX = 4, destinoY = 4;

    if (bfs(matriz, inicioX, inicioY, destinoX, destinoY))
        printf("COPS\n");
    else
        printf("ROBBERS\n");
}

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        int matriz[TAMANHO][TAMANHO];

        for (int i = 0; i < TAMANHO; i++)
            for (int j = 0; j < TAMANHO; j++)
                scanf("%d", &matriz[i][j]);

        resolver(matriz);
    }

    return 0;
}
