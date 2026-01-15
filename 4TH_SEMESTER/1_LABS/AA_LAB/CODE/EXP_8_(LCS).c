#include <stdio.h>
#include <string.h>

#define MAX 100

// Function to find the length of the longest common subsequence
int lcs(char *X, char *Y, int m, int n) {
    int L[MAX][MAX]; // Create a 2D array (for storing lengths of LCS)

    // Build the array (bottom-up)
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                L[i][j] = 0; // If either string empty
            } else if (X[i - 1] == Y[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1; // Characters match
            } else {
                L[i][j] = (L[i - 1][j] > L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1]; //max
            }
        }
    }

    return L[m][n]; // Length of LCS
}

int main() {
    char X[MAX], Y[MAX];


    printf("Enter first string: ");
    scanf("%s", X);
    printf("Enter second string: ");
    scanf("%s", Y);

    int m = strlen(X);
    int n = strlen(Y);

    int length = lcs(X, Y, m, n);
    printf("Length of Longest Common Subsequence: %d\n", length);

    return 0;
}
