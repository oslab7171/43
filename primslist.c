#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure to represent an edge in the graph
struct Edge {
    int dest;
    int weight;
    struct Edge* next;
};

// Structure to represent a vertex and its adjacency list
struct Vertex {
    int key;
    struct Edge* head;
};

// Structure to represent the graph
struct Graph {
    int V; // Number of vertices
    struct Vertex* array; // Array of vertices
};

// Function to create a new graph with V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct Vertex*)malloc(V * sizeof(struct Vertex));

    // Initialize vertices and their adjacency lists
    for (int i = 0; i < V; ++i) {
        graph->array[i].key = INT_MAX;
        graph->array[i].head = NULL;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest, int weight) {
    // Add edge from src to dest
    struct Edge* newEdge = (struct Edge*)malloc(sizeof(struct Edge));
    newEdge->dest = dest;
    newEdge->weight = weight;
    newEdge->next = graph->array[src].head;
    graph->array[src].head = newEdge;

    // Add edge from dest to src (since the graph is undirected)
    newEdge = (struct Edge*)malloc(sizeof(struct Edge));
    newEdge->dest = src;
    newEdge->weight = weight;
    newEdge->next = graph->array[dest].head;
    graph->array[dest].head = newEdge;
}

// Function to print the MST using Prim's algorithm
void primMST(struct Graph* graph) {
    int parent[graph->V];  // To store the parent of each vertex in MST
    int key[graph->V];     // To store the key value of each vertex
    int inMST[graph->V];   // To check whether a vertex is in MST

    // Initialize key values and inMST array
    for (int i = 0; i < graph->V; ++i) {
        key[i] = INT_MAX;
        inMST[i] = 0;
    }

    // Start with the first vertex
    key[0] = 0;
    parent[0] = -1;  // First vertex is the root

    // Construct MST
    for (int count = 0; count < graph->V - 1; ++count) {
        // Find the vertex with the minimum key value
        int minKey = INT_MAX, minIndex;

        for (int v = 0; v < graph->V; ++v) {
            if (inMST[v] == 0 && key[v] < minKey) {
                minKey = key[v];
                minIndex = v;
            }
        }

        // Add the selected vertex to the MST
        inMST[minIndex] = 1;

        // Update key values and parent for adjacent vertices
        struct Edge* pCrawl = graph->array[minIndex].head;
        while (pCrawl != NULL) {
            int v = pCrawl->dest;
            if (inMST[v] == 0 && pCrawl->weight < key[v]) {
                parent[v] = minIndex;
                key[v] = pCrawl->weight;
            }
            pCrawl = pCrawl->next;
        }
    }

    // Print the MST
    printf("Edges in MST:\n");
    for (int i = 1; i < graph->V; ++i) {
        printf("Edge: %d - %d\tWeight: %d\n", parent[i], i, key[i]);
    }
}

// Main function
int main() {
    int V, E;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    struct Graph* graph = createGraph(V);

    printf("Enter the number of edges: ");
    scanf("%d", &E);

    for (int i = 0; i < E; ++i) {
        int src, dest, weight;
        printf("Enter edge %d (src dest weight): ", i + 1);
        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(graph, src, dest, weight);
    }

    // Apply Prim's algorithm and print the MST
    primMST(graph);

    return 0;
}
