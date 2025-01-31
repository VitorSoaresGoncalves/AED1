#include <stdio.h>
#include <string.h>

#define MAX 201

int lcs_length(const char *s1, const char *s2) {
    int m = strlen(s1);
    int n = strlen(s2);
    int dp[MAX][MAX] = {0};

    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }
    return dp[m][n];
}

void print_supersequence(const char *s1, const char *s2) {
    int m = strlen(s1);
    int n = strlen(s2);
    int dp[MAX][MAX] = {0};

    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }

   
    char result[MAX * 2];
    int index = 0;
    int i = m, j = n;

    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            result[index++] = s1[i - 1];
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            result[index++] = s1[i - 1];
            i--;
        } else {
            result[index++] = s2[j - 1];
            j--;
        }
    }

   
    while (i > 0) {
        result[index++] = s1[i - 1];
        i--;
    }
    while (j > 0) {
        result[index++] = s2[j - 1];
        j--;
    }

    
    for (int k = index - 1; k >= 0; k--) {
        putchar(result[k]);
    }
    putchar('\n');
}

int main() {
    char s1[MAX], s2[MAX];
    int test_case = 1;

    while (1) {
       
        fgets(s1, sizeof(s1), stdin);
        if (s1[0] == '#') break;
        fgets(s2, sizeof(s2), stdin);

        
        s1[strcspn(s1, "\n")] = 0;
        s2[strcspn(s2, "\n")] = 0;

        
        printf("Teste %d\n", test_case++);
        
        
        print_supersequence(s1, s2);
        
       
        printf("\n");
    }

    return 0;
}
