#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

int V; // Number of vertices in the graph (user-defined)

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
        total_weight += graph[parent[i]][i];
    }
    printf("Total weight of MST: %d\n", total_weight);
}

// Function to construct MST using Prim's algorithm
void primMST(int graph[V][V])
{
    int parent[V]; // Array to store MST
    int key[V];    // Key values used to pick the minimum weight edge
    bool mstSet[V]; // To track included vertices in MST

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    printMST(parent, graph);
}

// Driver code
int main()
{
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    int graph[V][V];
    printf("Enter the adjacency matrix (%dx%d) for the graph:\n", V, V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    primMST(graph);
    return 0;
}




















/*   

Enter the number of vertices: 5
Enter the adjacency matrix (5x5) for the graph:
0 2 0 6 0
2 0 3 8 5
0 3 0 0 7
6 8 0 0 9
0 5 7 9 0

Edge 	Weight
0 - 1 	2 
1 - 2 	3 
0 - 3 	6 
1 - 4 	5 
Total weight of MST: 16


*/