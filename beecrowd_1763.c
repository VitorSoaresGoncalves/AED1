#include <stdio.h>
#include <string.h>

#define MAX_PAIS 30
#define MAX_NOME 100

typedef struct {
    char pais[MAX_NOME];
    char mensagem[MAX_NOME];
} Natal;

int main() {
   
    Natal banco[] = {
        {"brasil", "Feliz Natal!"},
        {"alemanha", "Frohliche Weihnachten!"},
        {"austria", "Frohe Weihnacht!"},
        {"coreia", "Chuk Sung Tan!"},
        {"espanha", "Feliz Navidad!"},
        {"grecia", "Kala Christougena!"},
        {"estados-unidos", "Merry Christmas!"},
        {"inglaterra", "Merry Christmas!"},
        {"australia", "Merry Christmas!"},
        {"portugal", "Feliz Natal!"},
        {"suecia", "God Jul!"},
        {"turquia", "Mutlu Noeller"},
        {"argentina", "Feliz Navidad!"},
        {"chile", "Feliz Navidad!"},
        {"mexico", "Feliz Navidad!"},
        {"antardida", "Merry Christmas!"},
        {"canada", "Merry Christmas!"},
        {"irlanda", "Nollaig Shona Dhuit!"},
        {"belgica", "Zalig Kerstfeest!"},
        {"italia", "Buon Natale!"},
        {"libia", "Buon Natale!"},
        {"siria", "Milad Mubarak!"},
        {"marrocos", "Milad Mubarak!"},
        {"japao", "Merii Kurisumasu!"}
    };

    int totalPaises = sizeof(banco) / sizeof(banco[0]);
    char paisEntrada[MAX_NOME];
    int encontrado, i;

    
    while (scanf("%s", paisEntrada) != EOF) {
        encontrado = 0;

        
        for (i = 0; i < totalPaises; i++) {
            if (strcmp(paisEntrada, banco[i].pais) == 0) {
                printf("%s\n", banco[i].mensagem);
                encontrado = 1;
                break;
            }
        }

        
        if (!encontrado) {
            printf("--- NOT FOUND ---\n");
        }
    }

    return 0;
}
