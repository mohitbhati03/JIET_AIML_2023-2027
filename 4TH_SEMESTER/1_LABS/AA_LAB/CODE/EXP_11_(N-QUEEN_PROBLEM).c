#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printSolution(int **board, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf(" %d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool isSafe(int **board, int row, int col, int N) {
    for (int i = 0; i < col; i++)
        if (board[row][i]) return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;
    for (int i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j]) return false;
    return true;
}

void solveNQUtil(int **board, int col, int N) {
    if (col >= N) {
        printSolution(board, N);
        return;
    }
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col, N)) {
            board[i][col] = 1;
            solveNQUtil(board, col + 1, N);
            board[i][col] = 0; // BACKTRACK
        }
    }
}

void solveNQ(int N) {
    int **board = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        board[i] = (int *)malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) board[i][j] = 0;
    }
    solveNQUtil(board, 0, N);
    for (int i = 0; i < N; i++) free(board[i]);
    free(board);
}

int main() {
    int N;
    printf("Enter the size of the board (N): ");
    scanf("%d", &N);
    printf("All possible solutions for %d-Queens problem:\n", N);
    solveNQ(N);
    return 0;
}