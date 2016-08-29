#include <bits/stdc++.h>
using namespace std;

class Graph {
	int V;
	list<int> *adj; 
	void dfsUtil(int v, bool visited[]);
public:
	Graph(int V);
	void addEdge(int v, int w);
	void dfs(int v);
};

Graph::Graph(int V) {
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
	adj[v].push_back(w);
	adj[w].push_back(v);
}

void Graph::dfsUtil(int v, bool visited[]) {
	cout<<v<<" ";
	visited[v] = true;
	list<int>::iterator it;
	for(it = adj[v].begin(); it!=adj[v].end(); it++) {
		if(!visited[*it]) 
			dfsUtil(*it, visited);
	}
}

void Graph::dfs(int v) {
	bool *visited = new bool[V];
	for(int i=0; i<V; i++) {
		visited[i] = false;
	}
	dfsUtil(v, visited);
}

int main() {
	Graph g(5);
	g.addEdge(0, 1);
	g.addEdge(0, 4);
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(1, 4);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.dfs(2);
	return 0;
}
