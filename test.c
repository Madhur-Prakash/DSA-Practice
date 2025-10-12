#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b)? a : b;
}

int lcs(char X [], char Y []){
    int m = strlen(X);
    int n = strlen(Y);
    int dp[m+1][n+1];

    for (int i =0; i <= m; i++){
        for (int j =0; j <= n; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            } else if (X[i-1] == Y[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            } else{
                printf("value at dp[i-1][j] is %d and value at dp[i][j-1] is %d\n", dp[i-1][j], dp[i][j-1]);
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
    }
    return dp[m][n];
}
}

int main() {
    char s[] = "bbbab";
    int n = strlen(s);
    char rev_s[n+1];
    strcpy(rev_s, s);

    // Reverse the string
    for(int i = 0; i < n/2; i++) {
        char temp = rev_s[i];
        rev_s[i] = rev_s[n-1-i];
        rev_s[n-1-i] = temp;
    }

    // Find LCS between original and reversed string
    printf("Length of LPS: %d\n", lcs(s, rev_s));
    return 0;
}