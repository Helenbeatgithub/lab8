/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define NODES 4

struct Node{
    int dest;
    struct Node* next;
};

struct List{
    struct Node *head;
};

struct Graph{
    int V;
    struct List* array;
};

struct Node* createNode(int dest) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V){
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph)); // Changed from struct Node to struct Graph
    graph->V = V;

    graph->array = (struct List*) malloc (V * sizeof(struct List));
    for( int i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}

void addEdgeList(struct Graph* graph, int src, int dest) { // Renamed to addEdgeList
    struct Node* newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->V; ++v) {
        struct Node* node = graph->array[v].head;
        printf("%d: ", v);
        while (node) {
            printf("%d->", node->dest);
            node = node->next;
        }
        printf("NULL\n");
    }
}


void addEdge(int adjMatrix[NODES][NODES], int src, int dest){
    adjMatrix[src][dest] = 1;
}

void printAdjMatrix(int adjMatrix[NODES][NODES]){
    int i, j;
    for(i = 0; i < NODES; i++){
        for(j = 0; j < NODES; j++){
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int adjMatrix[NODES][NODES] = {0};

    addEdge(adjMatrix, 0, 1);
    addEdge(adjMatrix, 0, 2);
    addEdge(adjMatrix, 1, 2);
    addEdge(adjMatrix, 2, 0);
    addEdge(adjMatrix, 3, 2);

    printf("Adjacency Matrix:\n");
    printAdjMatrix(adjMatrix);

    struct Graph* graph = createGraph(NODES);
    addEdgeList(graph, 0, 1); // Changed to addEdgeList
    addEdgeList(graph, 0, 2); 
    addEdgeList(graph, 1, 2); 
    addEdgeList(graph, 2, 0); 
    addEdgeList(graph, 3, 2); 

    printf("Adjacency List:\n");
    printGraph(graph);

    return 0;
}
