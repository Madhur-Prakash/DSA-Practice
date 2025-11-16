#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void lcs(char X[], char Y[]) {
    int m = strlen(X);
    int n = strlen(Y);

    int dp[m + 1][n + 1];

    // Build DP table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0){
                dp[i][j] = 0;
                printf("%d ", dp[i][j]);}

            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;

            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Print DP table
    printf("\nDP TABLE:\n");
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }

    // Reconstruct LCS
    int index = dp[m][n];
    char lcs[index + 1];
    lcs[index] = '\0';

    int i = m, j = n;

    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1] = X[i - 1];
            i--; j--; index--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    printf("\nLCS: %s\n", lcs);
}

int main() {
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    lcs(X, Y);
    return 0;
}
