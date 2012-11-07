#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100
#define IN 255

int dijkstra(int cost[][N], int source, int target) {
	int dist[N];
	int prev[N];
	int selected[N] = {0};
	int i, m, min, start, d, j;
	char path[N];
	
	for (i = 0; i < N; i++) {
		dist[i] = IN;
		prev[i] = -1;
	}
	
	start = source;
	selected[start] = 1;
	dist[start] = 0;
	
	while (selected[target] == 0) {
		min = IN;
		m = 0;
		
		for (i = 0; i < N; i++) {
			if (selected[i]) continue;
			
			d = dist[start] + cost[start][i];
			if (d < dist[i]) {
				dist[i] = d;
				prev[i] = start;
			}
			
			if (min > dist[i]) {
				min = dist[i];
				m = i;
			}
		}
		
		start = m;
		selected[start] = 1;
	}
		
	start = target;
	j = 0;
	while (start != -1) {
		path[j++] = start;
		start = prev[start];
	}
	for (i = 0; i < j; i++)
		if (i < j - 1)
			printf("%d-", path[j - i - 1]);
		else
			printf("%d", path[j - i - 1]);
	printf("\n");
	
	return dist[target];
}

int main() {
	int cost[N][N], i, j, w, ch, co;
	int source, target, x, y;
	printf("DIJKSTRA ALGORITHM\n");
	for (i = 0; i < N; i++)
		for (j = i; j < N; j++) {
			if (i == j)
				cost[i][j] = 0;
			else
				cost[i][j] = cost[j][i] = IN;
		}
//	
	for (i = 0; i < N; i++) {
		for (j = i; j < N; j++) {
			if (i != j)
			cost[i][j] = cost[j][i] =  rand() % 32 + 1;
			printf("cost[%d][%d] = %d\n", i, j, cost[i][j]);
		}
	}
	
	printf("Enter source: ");
	scanf("%d", &source);
	printf("\nEnter target: ");
	scanf("%d", &target);
	
	co = dijkstra(cost, source, target);
	printf("\nPath: %d", co);
	
	return 0;
}