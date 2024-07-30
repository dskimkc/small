#include<stdio.h>
#include<string.h>
int max(int a,int b){
    if(a>b)return a;
    else return b;
}
void findLCS(char first[], char second[], int len1, int len2) {
    int dp[100][100];
    char lcs[100];
    int i, j;
    // Initialize the dp array and calculate LCS length
    for (i = 0; i <= len1; i++) {
        for (j = 0; j <= len2; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (first[i - 1] == second[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    printf("LCS length is %d\n", dp[len1][len2]);
    // Backtrack to find the LCS
    int ansl = dp[len1][len2];
    lcs[ansl] = '\0';
    i = len1;
    j = len2;
    while (i > 0 && j > 0) {
        if (first[i - 1] == second[j - 1]) {
            lcs[ansl - 1] = first[i - 1];
            i--;
            j--;
            ansl--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    printf("The LCS is %s\n", lcs);
}
int main() {
    char first[100], second[100];
    printf("Enter the first string: ");
    scanf("%s", first);
    printf("Enter the second string: ");
    scanf("%s", second);
    int len1 = strlen(first);
    int len2 = strlen(second);
    findLCS(first, second, len1, len2);
    return 0;
}