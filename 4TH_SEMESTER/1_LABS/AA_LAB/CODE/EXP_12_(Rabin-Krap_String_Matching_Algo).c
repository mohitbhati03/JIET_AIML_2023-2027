#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define d 256 // Number of characters in the input alphabet
#define q 101 // A prime number

void rabinKarp(char *text, char *pattern, int N, int M) {
    int p = 0, t = 0, h = 1;

    // Calculate h = pow(d, M-1) % q
    for (int i = 0; i < M - 1; i++)
        h = (h * d) % q;

    // Calculate initial hash values for pattern and text
    for (int i = 0; i < M; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide the pattern over text
    for (int i = 0; i <= N - M; i++) {
        if (p == t) {
            int j;
            for (j = 0; j < M; j++)
                if (text[i + j] != pattern[j]) break;
            if (j == M) printf("Pattern found at index %d\n", i);
        }
        if (i < N - M) {
            t = (d * (t - text[i] * h) + text[i + M]) % q;
            if (t < 0) t += q; // Ensure positive hash
        }
    }
}

int main() {
    int N, M;

    // Get sizes from user
    printf("Enter the size of the text: ");
    scanf("%d", &N);
    getchar(); // Consume newline character

    printf("Enter the size of the pattern: ");
    scanf("%d", &M);
    getchar(); // Consume newline character

    // Allocate memory for text and pattern
    char *text = (char *)malloc((N + 1) * sizeof(char));
    char *pattern = (char *)malloc((M + 1) * sizeof(char));

    // Get text and pattern from user
    printf("Enter the text: ");
    fgets(text, N + 1, stdin);
    text[strcspn(text, "\n")] = 0; // Remove newline

    printf("Enter the pattern: ");
    fgets(pattern, M + 1, stdin);
    pattern[strcspn(pattern, "\n")] = 0; 

    
    rabinKarp(text, pattern, N, M);

    
    free(text);
    free(pattern);

    return 0;
}