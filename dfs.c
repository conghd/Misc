#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define maxVertices 100

void dfs(int graph[][maxVertices], int *size, int presentVertex, int *visited) {
	visited[presentVertex] = 1;
	
	int i = 0;
	for (i = 0; i < size[presentVertex]; i++) {
		if (!visited[graph[presentVertex][i]]) {
			printf("Visiting vertext: %d\n", presentVertex);
			dfs(graph, size, graph[presentVertex][i], visited);
		}
	}
}

int main() {
	int graph[maxVertices][maxVertices];
	int size[maxVertices] = { 0};
	int visited[maxVertices] = { 0 };
	
	int vertices, edges, iter;
	printf("Number of vertices & edges:");
	scanf("%d%d", &vertices, &edges);
	int vertex1, vertex2;
	
	for (iter = 0; iter < vertices; iter++) {
		printf("vertex1, vertex 2: ");
		scanf("%d%d", &vertex1, &vertex2);
		assert(vertex1 >= 0 && vertex1 < vertices);
		assert(vertex2 >= 0 && vertex2 < vertices);
		graph[vertex1][size[vertex1]++] = vertex2;
	}
	
	int presentVertex;
	for (presentVertex = 0; presentVertex < vertices; presentVertex++) {
		if (!visited[presentVertex]) {
			dfs(graph, size, presentVertex, visited);
		}
	}
	
	return;
}