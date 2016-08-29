#include <bits/stdc++.h>
using namespace std;
#define V 9
int dist[V];
bool visited[V];

int minDist() {
  int min_index;
	int min = INT_MAX;
 	for(int i=0; i<V; i++){
    if(!visited[i] && dist[i] <= min) {
      min = dist[i];
      min_index = i;
    }
  }
  return min_index;
}

void show() {
	for(int v=0; v<V; v++) {
		cout << v <<" "<< dist[v] << "\n";
	}
}

void dijkstra(int graph[V][V], int src) {
	for(int v=0; v<V; v++) {
		dist[v] = INT_MAX;
		visited[v] = false;
	}
	dist[src] = 0;
	for(int i=0; i<V-1; i++) {
		int u = minDist();
		visited[u] = true;
		for(int v=0; v<V; v++) {
			if(graph[u][v] && !visited[v] && dist[u] != INT_MAX && dist[v] > dist[u] + graph[u][v]) {
				dist[v] = dist[u] + graph[u][v];
			}
		}
	}
	show();
}

int main(int argc, char const *argv[]) {
	int graph[V][V] = {
		{0, 4, 0, 0, 0, 0, 0, 8, 0},
    {4, 0, 8, 0, 0, 0, 0, 11, 0},
    {0, 8, 0, 7, 0, 4, 0, 0, 2},
    {0, 0, 7, 0, 9, 14, 0, 0, 0},
    {0, 0, 0, 9, 0, 10, 0, 0, 0},
    {0, 0, 4, 0, 10, 0, 2, 0, 0},
    {0, 0, 0, 14, 0, 2, 0, 1, 6},
    {8, 11, 0, 0, 0, 0, 1, 0, 7},
    {0, 0, 2, 0, 0, 0, 6, 7, 0}
	};
	dijkstra(graph, 0);
	return 0;
}
