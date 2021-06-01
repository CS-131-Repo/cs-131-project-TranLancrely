// Reference: https://www.tutorialspoint.com/cplusplus-program-for-dijkstra-s-shortest-path-algorithm 

#include<iostream>

using namespace std;

#define infinite 999
#define max 5
void Dijkstra(int graph[max][max], int n, int beginNode);

int main() {
	int graph[max][max] = { {0,1,0,6,10},{1,0,6,0,0},{0,7,0,4,2},{1,0,4,0,8},{9,0,2,5,0} };
	int x = 5;
	int y = 0;
	Dijkstra(graph, x, y);

	return 0;
}

void Dijkstra(int graph[max][max], int n, int beginNode) {
	int i, j, count, minDist, next, visited[max];
	int distCost[max][max], distance[max], prev[max];
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (graph[i][j] == 0)
				distCost[i][j] = infinite;
			else
				distCost[i][j] = graph[i][j];
	for (i = 0; i < n; i++) {
		distance[i] = distCost[beginNode][i];            // set vertices to infinite
		prev[i] = beginNode;
		visited[i] = 0;
	}
	distance[beginNode] = 0;							 // source vertex will be 0
	visited[beginNode] = 1;
	count = 1;
	while (count < n - 1) {
		minDist = infinite;
		for (i = 0; i < n; i++)
			if (distance[i] < minDist && !visited[i]) {  // pushes source vertex in prio queue
				minDist = distance[i];                   // pop vertex with min dist
				next = i;
			}
		visited[next] = 1;								// visited, path update
		for (i = 0; i < n; i++)
			if (!visited[i])
				if (minDist + distCost[next][i] < distance[i]) {
					distance[i] = minDist + distCost[next][i];    // update min distance
					prev[i] = next;							      // pushes vertex 
				}
		count++;
	}
	for (i = 0; i < n; i++)
		if (i != beginNode) {
			cout << "Node " << i << " distance: " << distance[i] << endl;
			cout << "Path = " << i;
			j = i;
			do {
				j = prev[j];
				cout << " << " << j;
			} while (j != beginNode);
			cout << endl;
		}
}