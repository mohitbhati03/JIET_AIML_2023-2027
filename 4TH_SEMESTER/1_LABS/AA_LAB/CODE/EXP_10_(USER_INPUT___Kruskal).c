#include <stdio.h>

#define MAX 100  

// Structure to represent an edge  
struct Edge {
    int src, dest, weight;
};

// Structure to represent a graph  
struct Graph {
    int V, E;  // Number of vertices and edges
    struct Edge edges[MAX];  // Array of edges
};

// Function to find the parent of a node (for Union-Find)  
int findParent(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return findParent(parent, parent[i]);
}

// Function to perform union of two sets  
void unionSets(int parent[], int x, int y) {
    int xset = findParent(parent, x);
    int yset = findParent(parent, y);
    if (xset != yset)
        parent[xset] = yset;
}

// Function to sort edges by weight (Bubble Sort for simplicity)  
void sortEdges(struct Edge edges[], int E) {
    for (int i = 0; i < E - 1; i++) {
        for (int j = 0; j < E - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

// Kruskal’s Algorithm  
void kruskalMST(struct Graph *graph) {
    int V = graph->V;
    struct Edge result[MAX];  // Stores MST edges
    int parent[MAX];  // Parent array for Union-Find
    int e = 0, i = 0;  // Counters

    // Initialize parent array (-1 means no parent)
    for (int i = 0; i < V; i++)
        parent[i] = -1;

    // Step 1: Sort all edges by weight  
    sortEdges(graph->edges, graph->E);

    // Step 2: Pick the smallest edge and check for cycles  
    while (e < V - 1 && i < graph->E) {
        struct Edge nextEdge = graph->edges[i++];
        int x = findParent(parent, nextEdge.src);
        int y = findParent(parent, nextEdge.dest);

        // If including this edge doesn't form a cycle, include it in the MST
        if (x != y) {
            result[e++] = nextEdge;
            unionSets(parent, x, y);
        }
    }

    // Print the MST  
    printf("Edges in Minimum Spanning Tree (MST):\n");
    int minCost = 0;
    for (i = 0; i < e; i++) {
        printf("%d - %d => %d\n", result[i].src, result[i].dest, result[i].weight);
        minCost += result[i].weight;
    }
    printf("Total Minimum Cost: %d\n", minCost);
}

// Driver Code  
int main() {
    struct Graph graph;

    // Input: Number of vertices and edges  
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &graph.V, &graph.E);

    printf("Enter edges (source, destination, weight):\n");
    for (int i = 0; i < graph.E; i++) {
        scanf("%d %d %d", &graph.edges[i].src, &graph.edges[i].dest, &graph.edges[i].weight);
    }

    // Run Kruskal’s Algorithm  
    kruskalMST(&graph);

    return 0;
}
















/*

Enter number of vertices and edges: 5 7
Enter edges (source, destination, weight):
0 1 2
1 2 3
1 4 5 
0 3 6
2 4 7
1 3 8
3 4 9
Edges in Minimum Spanning Tree (MST):
0 - 1 => 2
1 - 2 => 3
1 - 4 => 5
0 - 3 => 6
Total Minimum Cost: 16

*/