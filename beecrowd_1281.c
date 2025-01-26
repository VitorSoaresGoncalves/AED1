#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 100
#define MAX_NOME 51

typedef struct {
    char nome[MAX_NOME];
    double preco;
} Produto;

int main() {
    int n, m, p, i, j, k;
    char nomeProduto[MAX_NOME];
    int quantidade;
    double total;

    
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        
        scanf("%d", &m);

        Produto produtos[MAX_PRODUTOS];

        
        for (j = 0; j < m; j++) {
            scanf("%s %lf", produtos[j].nome, &produtos[j].preco);
        }

        
        scanf("%d", &p);

        total = 0.0;

       
        for (j = 0; j < p; j++) {
            scanf("%s %d", nomeProduto, &quantidade);

            for (k = 0; k < m; k++) {
                if (strcmp(nomeProduto, produtos[k].nome) == 0) {
                    total += produtos[k].preco * quantidade;
                    break;
                }
            }
        }

        
        printf("R$ %.2lf\n", total);
    }

    return 0;
}
