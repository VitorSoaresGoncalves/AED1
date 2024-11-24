#include <stdio.h>
#include <string.h>

void Intercala(int p, int q, int r, char v[][21], char temp[][21]) {
    int i = p, j = q, k = 0;
    while (i < q && j < r) {
        if (strcmp(v[i], v[j]) <= 0) {
            strcpy(temp[k++], v[i++]);
        } else {
            strcpy(temp[k++], v[j++]);
        }
    }
    while (i < q) {
        strcpy(temp[k++], v[i++]);
    }
    while (j < r) {
        strcpy(temp[k++], v[j++]);
    }
    for (i = 0; i < k; i++) {
        strcpy(v[p + i], temp[i]);
    }
}

void Mergesort(int p, int r, char v[][21], char temp[][21]) {
    if (p < r - 1) {
        int q = (p + r) / 2;
        Mergesort(p, q, v, temp);
        Mergesort(q, r, v, temp);
        Intercala(p, q, r, v, temp);
    }
}

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    char alunos[x][21], temp[x][21];
    for (int i = 0; i < x; i++) {
        scanf("%s", alunos[i]);
    }
    Mergesort(0, x, alunos, temp);
    printf("%s\n", alunos[y - 1]);
    return 0;
}
