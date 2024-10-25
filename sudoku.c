https://judge.beecrowd.com/pt/runs/code/42150533


CODIGO:

#include <stdio.h>
int pode(int x, int V[9][9], int l, int c){
    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            if (V[i][c] == x || V[l][j]== x)
                return 0;
        }
    }
    int Bl = (l/3)*3, Bc = (c/3)*3;
    for (int i= Bl; i< Bl+3; i++){
        for (int j=Bc; j<Bc+3; j++){
            if (V[i][j]==x)
                return 0;
        }
    }
    return 1;
}
int main(){
    int jogo=0, V[9][9]={0}, x, instancia,n=1;
    scanf ("%d", &jogo);
    while (jogo > 0){
        for (int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                scanf ("%d", &x);
                if (pode(x, V, i,j)){
                    V[i][j] = x ;
                }
                else {
                    instancia = 1;
                }
            }
        }
         printf("Instancia %d\n", n);
        if(!instancia){
            printf("SIM\n\n");
        }
        else{
            printf("NAO\n\n");
        }

        instancia = 0;
        jogo--;
        n++;
        for (int i=0; i<9; i++){
            for (int j=0; j<9; j++){
              V[i][j] = 0;
            }
        }
    }
}
