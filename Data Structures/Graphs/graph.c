#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct AdjListNode {
	int data;
	struct AdjListNode* next;
};

struct AdjList {
	struct AdjListNode* head;
};

struct Graph {
	int V;
	struct AdjList* array;
};

struct AdjListNode* newNode(int data) {
	struct AdjListNode* node = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
	node->data = data;
	node->next = NULL;
	return node;
}

struct Graph* createGraph(int V) {

	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
	graph->V = V;
	graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));	
	for(int i=0; i<V; i++)
		graph->array[i].head = NULL;
	
	return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
	struct AdjListNode* node = newNode(dest);
	node->next = graph->array[src].head;
	graph->array[src].head = node;

	//newNode is allocating new memory. 
	//node = newNode(src);
	node->data = src;
	node->next = graph->array[dest].head;
	graph->array[dest].head = node;
}

void printGraph(struct Graph* graph) {
	for(int v=0; v < graph->V; v++) {
		struct AdjListNode* temp = graph->array[v].head;
		printf("Vertex %d:\n", v); 
		while(temp) {
			printf("->%d", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}

int main() {
	int m, n, V, E;
	printf("Vertices: ");
	scanf("%d", &V);
	printf("Edges: ");
	scanf("%d", &E);
	struct Graph* graph = createGraph(V);
	
	for(int i=0; i<E; i++) {
		scanf("%d%d", &m, &n);
		addEdge(graph, m, n);
	}
	printGraph(graph);
	return 0;
}
