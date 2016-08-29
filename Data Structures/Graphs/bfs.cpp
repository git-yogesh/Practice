#include <iostream>
#include <list>
using namespace std;

class Graph {
	int V;
	list<int> *adj;
public:
	Graph(int V);
	void addEdge(int v, int w);
	void bfs(int s);
	void printGraph();
};

Graph::Graph(int V) {
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
	adj[v].push_back(w);
	adj[w].push_back(v);
}

void Graph::printGraph() {
	for(int v=0; v < Graph::V; v++) {
		list<int> crawl = adj[v];
		cout<<v;
		for(std::list<int>::iterator it = crawl.begin(); it!=crawl.end(); it++) {
			cout<<"->"<<*it;
		}
		cout<<"\n";
	}
}

void Graph::bfs(int s) {
	bool *visited = new bool[V];
	for(int i=0; i<V; i++) {
		visited[i] = false;
	}
	list<int> q;
	visited[s] = true;
	q.push_back(s);
	list<int>::iterator it; 
	while(!q.empty()) {
		s = q.front();
		cout<<s<<" ";
		q.pop_front();
		for(it = adj[s].begin(); it!=adj[s].end(); it++) {
			if(!visited[*it]) {
				q.push_back(*it);
				visited[*it] = true;
			}
		}
	}
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
	g.printGraph();
	g.bfs(0);
	return 0;
}
