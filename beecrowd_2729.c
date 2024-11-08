#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct itens{
    char item[21];
    struct itens *proximo;
} itens;

itens* criar_item(char *item){
    itens* novo_itens = (itens*) malloc (sizeof(itens));
    strcpy (novo_itens->item, item);
    novo_itens->proximo = NULL;
    return novo_itens;
    }
void AddEmOrdem(itens **cabeca , char *item){
    itens *atual = *cabeca , *anterior = NULL;
    while (atual != NULL && strcmp(atual->item, item)<0){
        anterior = atual;
        atual = atual->proximo;
    }
    if (atual != NULL && strcmp(atual->item, item)==0){
        return;
    }
    itens *novo_itens = criar_item(item);
    if (anterior == NULL){
        novo_itens->proximo = *cabeca ;
        *cabeca = novo_itens;
    }
    else{
        novo_itens->proximo = atual;
        anterior->proximo = novo_itens;
    }  
}
void freeM(itens *cabeca){
    itens *atual = cabeca;
    while(atual != NULL){
        itens *temp = atual;
        atual = atual->proximo;
        free (temp);
    }

}
void printar(itens *cabeca){
    itens *atual = cabeca;
    while(atual != NULL){
        printf("%s", atual->item);
        if(atual->proximo != NULL){
            printf(" ");
        }
        atual = atual->proximo;
    }
    printf("\n");
}
int main(){
    int n=0;
    scanf("%d", &n);
    getchar();
    itens *lista[n-1];

    for (int i=0; i<n; i++){
        char ITENS[99999];
        fgets(ITENS, 99999, stdin);
        itens *cabeca = NULL;
        char *item = strtok(ITENS, " \n");
        while(item != NULL){
            AddEmOrdem(&cabeca, item);
            item = strtok(NULL, " \n");    
            }
        lista[i] = cabeca;
        }
    for (int i=0; i<n; i++){
        printar(lista[i]);
        freeM(lista[i]);
        }
    
    return(0);
}
