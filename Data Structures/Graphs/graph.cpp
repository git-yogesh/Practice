#include <iostream>
#include <list>
using namespace std;

class Graph {
	int V;
	list<int> *adj;
public:
	Graph(int V);
	void addEdge(int v, int w);
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
	return 0;
}
