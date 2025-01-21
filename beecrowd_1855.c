#include <stdio.h>

#define MAX 100


int dx[] = {0, 0, 1, -1}; 
int dy[] = {1, -1, 0, 0}; 

int get_direction(char c) {
    if (c == '>') return 0;  
    if (c == '<') return 1; 
    if (c == 'v') return 2;  
    if (c == '^') return 3;  
    return -1;
}

int main() {
    int largura, altura;

   
    scanf("%d", &largura);
    scanf("%d", &altura);

    
    if (largura >= MAX || altura >= MAX) {
        printf("!\n");
        return 0;
    }

    char mapa[MAX][MAX];

    
    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < largura; j++) {
            scanf(" %c", &mapa[i][j]);
        }
    }

    
    int x = 0, y = 0; 
    int visitados[MAX][MAX] = {0}; 

   
    if (mapa[0][0] == '.') {
        printf("!\n");
        return 0;
    }

   
    int dir = get_direction(mapa[0][0]);
    if (dir == -1) { 
        printf("!\n");
        return 0;
    }

    while (1) {
        
        if (x < 0 || x >= altura || y < 0 || y >= largura) {
            printf("!\n");
            return 0;
        }

        
        if (mapa[x][y] == '*') {
            printf("*\n");
            return 0;
        }

       
        if (visitados[x][y]) {
            printf("!\n");
            return 0;
        }

        
        visitados[x][y] = 1;

        
        if (mapa[x][y] != '.') {
            dir = get_direction(mapa[x][y]);
            if (dir == -1) {
                printf("!\n");
                return 0;
            }
        }

        
        x += dx[dir];
        y += dy[dir];
    }

    return 0;
}
