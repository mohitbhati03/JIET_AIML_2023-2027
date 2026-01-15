#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

// Number of vertices in the graph
#define V 5

// Function to find the vertex with the minimum key value
int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

// Function to print the constructed MST and calculate total weight
void printMST(int parent[], int graph[V][V])
{
    int total_weight = 0;
    printf("Edge \tWeight\n");
    
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d \n", parent[i], i, graph[parent[i]][i]);
        total_weight += graph[parent[i]][i]; // Summing up MST edge weights
    }
    
    printf("Total weight of MST: %d\n", total_weight);
}

// Function to construct MST using Prim's algorithm
void primMST(int graph[V][V])
{
    int parent[V]; // Array to store the MST
    int key[V];    // Key values used to pick the minimum weight edge
    bool mstSet[V]; // To track included vertices in MST

    // Initialize all keys as INFINITE and MST set as false
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // Always include the first vertex in MST
    key[0] = 0;
    parent[0] = -1; // First node is always the root of MST

    // MST construction loop
    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet); // Get the minimum key vertex
        mstSet[u] = true; // Include it in MST

        // Update key values and parent index of adjacent vertices
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST and its weight
    printMST(parent, graph);
}

// Driver code
int main()
{
    int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };

    // Run Prim's algorithm and print the result
    primMST(graph);

    return 0;
}
