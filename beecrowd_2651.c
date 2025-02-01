#include <stdio.h>
#include <string.h>
#include <ctype.h>

void minuscula(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = minuscula(str[i]);
    }
}

int main() {
    char s[100001]; 
    scanf("%s", s);

    minuscula(s); 
    
    if (strstr(s, "zelda") != NULL) {
        printf("Link Bolado\n");
    } else {
        printf("Link Tranquilo\n");
    }

    return 0;
}
