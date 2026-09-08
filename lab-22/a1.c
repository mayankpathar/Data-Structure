
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 20

typedef struct Node {
	int vertex;
	struct Node *next;
} Node;

Node *graph[MAX_VERTICES];
int visited[MAX_VERTICES];

void addEdge(int first, int second) {
	Node *newNode = malloc(sizeof(Node));

	newNode->vertex = second;
	newNode->next = graph[first];
	graph[first] = newNode;

	newNode = malloc(sizeof(Node));
	newNode->vertex = first;
	newNode->next = graph[second];
	graph[second] = newNode;
}

void displayGraph(int vertices) {
	int i;
	Node *current;

	printf("\nAdjacency list:\n");
	for (i = 0; i < vertices; i++) {
		printf("%d: ", i);
		current = graph[i];
		while (current != NULL) {
			printf("%d ", current->vertex);
			current = current->next;
		}
		printf("\n");
	}
}

void dfs(int vertex) {
	Node *current;

	visited[vertex] = 1;
	printf("%d ", vertex);

	current = graph[vertex];
	while (current != NULL) {
		if (!visited[current->vertex]) {
			dfs(current->vertex);
		}
		current = current->next;
	}
}

void bfs(int start) {
	int queue[MAX_VERTICES];
	int front = 0;
	int rear = 0;
	Node *current;

	visited[start] = 1;
	queue[rear++] = start;

	while (front < rear) {
		int vertex = queue[front++];

		printf("%d ", vertex);
		current = graph[vertex];
		while (current != NULL) {
			if (!visited[current->vertex]) {
				visited[current->vertex] = 1;
				queue[rear++] = current->vertex;
			}
			current = current->next;
		}
	}
}

int main(void) {
	int vertices, edges, first, second, start;

	printf("Enter number of vertices (max %d): ", MAX_VERTICES);
	scanf("%d", &vertices);

	printf("Enter number of edges: ");
	scanf("%d", &edges);

	printf("Enter each edge (u v):\n");
	while (edges-- > 0) {
		scanf("%d %d", &first, &second);
		addEdge(first, second);
	}

	displayGraph(vertices);

	printf("\nEnter starting vertex: ");
	scanf("%d", &start);

	for (first = 0; first < vertices; first++) {
		visited[first] = 0;
	}
	printf("DFS: ");
	dfs(start);

	for (first = 0; first < vertices; first++) {
		visited[first] = 0;
	}
	printf("\nBFS: ");
	bfs(start);
	printf("\n");

	return 0;
}
