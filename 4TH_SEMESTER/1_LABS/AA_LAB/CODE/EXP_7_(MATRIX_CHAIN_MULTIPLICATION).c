#include <stdio.h>
#include <limits.h>

#define MAX 100

// Function to print the optimal parenthesization
void printOptimalParenthesization(int s[MAX][MAX], int i, int j) {
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        printOptimalParenthesization(s, i, s[i][j]);
        printOptimalParenthesization(s, s[i][j] + 1, j);
        printf(")");
    }
}

// Function to perform Matrix Chain Multiplication
void matrixChainOrder(int p[], int n) {
    int m[MAX][MAX]; // m[i][j] will hold the minimum cost
    int s[MAX][MAX]; // s[i][j] will hold the index of the optimal split

    // m[i][i] = 0 for all i
    for (int i = 1; i <= n; i++) {
        m[i][i] = 0;
    }

    // l is the chain length
    for (int l = 2; l <= n; l++) { // l = 2 to n
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX; // Initialize to a large value
            for (int k = i; k < j; k++) {
                // q = cost/scalar multiplications
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k; // Store the index of the split
                }
            }
        }
    }

    
    printf("Minimum number of multiplications is: %d\n", m[1][n]);
    printf("Optimal Parenthesization: ");
    printOptimalParenthesization(s, 1, n);
    printf("\n");
}

int main() {
    int n;
    int p[MAX];

    
    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    
    printf("Enter the dimensions of the matrices (p0, p1, ..., pn):\n");
    for (int i = 0; i <= n; i++) {
        printf("p[%d]: ", i);
        scanf("%d", &p[i]);
    }

    matrixChainOrder(p, n);

    return 0;
}