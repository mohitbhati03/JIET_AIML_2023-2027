#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to solve knapsack problem
void knapsack(int n, int capacity, int weights[], int values[]) {
    int dp[n + 1][capacity + 1];
    int included[n];
    
    // Initialize the included array
    for(int i = 0; i < n; i++) {
        included[i] = 0;
    }
    
    // Build dp table
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= capacity; j++) {
            // Base case
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            // If weight of current item is less than capacity
            else if(weights[i-1] <= j) {
                int including = values[i-1] + dp[i-1][j-weights[i-1]];
                int excluding = dp[i-1][j];
                dp[i][j] = (including > excluding) ? including : excluding;
            }
            // If weight is more than capacity
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    // Find included items
    int i = n, j = capacity;
    while(i > 0 && j > 0) {
        if(dp[i][j] != dp[i-1][j]) {
            included[i-1] = 1;
            j = j - weights[i-1];
        }
        i--;
    }
    
    // Print results
    printf("\nKnapsack Results:\n");
    printf("Capacity: %d\n\n", capacity);
    printf("Items Selected:\n");
    int total_value = 0, total_weight = 0;
    
    for(i = 0; i < n; i++) {
        if(included[i]) {
            printf("Item %d: Weight = %d, Value = %d\n", 
                   i+1, weights[i], values[i]);
            total_value += values[i];
            total_weight += weights[i];
        }
    }
    
    printf("\nTotal Value: %d\n", total_value);
    printf("Total Weight: %d\n", total_weight);
}

int main() {
    int n = 5;  // Number of items
    int capacity = 50;  // Knapsack capacity
    
    // Arrays to store weights and values
    int weights[5] = {10, 20, 30, 40, 50};
    int values[5] = {60, 100, 120, 140, 150};
    
    // Call knapsack function
    knapsack(n, capacity, weights, values);
    
    return 0;
}