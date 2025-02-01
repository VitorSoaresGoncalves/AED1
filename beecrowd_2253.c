#include <stdio.h>
#include <string.h>
#include <ctype.h>

int validarSenha(char *senha) {
    int temMaiuscula = 0, temMinuscula = 0, temNumero = 0;
    int tamanho = strlen(senha);

    
    if (tamanho < 6 || tamanho > 32) {
        return 0;
    }

    for (int i = 0; i < tamanho; i++) {
        char c = senha[i];

      
        if (!isalnum(c)) {
            return 0;
        }

        
        if (isupper(c)) {
            temMaiuscula = 1;
        }

        
        if (islower(c)) {
            temMinuscula = 1;
        }

       
        if (isdigit(c)) {
            temNumero = 1;
        }
    }

    
    return temMaiuscula && temMinuscula && temNumero;
}

int main() {
    char senha[101];

    while (fgets(senha, 101, stdin)) {
        
        senha[strcspn(senha, "\n")] = '\0';

        if (validarSenha(senha)) {
            printf("Senha valida.\n");
        } else {
            printf("Senha invalida.\n");
        }
    }

    return 0;
}
