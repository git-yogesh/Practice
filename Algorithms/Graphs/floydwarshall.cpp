#include <bits/stdc++.h>
using namespace std;
#define INF 99999
#define V 4
void show(int dist[][V]) {
  for(int i=0; i<V; i++) {
    for(int j=0; j<V; j++) {
      cout<<dist[i][j]<<" ";
    }
    cout<<endl;
  }
}

void floyd(int graph[][V]) {
  int dist[V][V];
  for(int i=0; i<V; i++) {
    for(int j=0; j<V; j++) {
      dist[i][j] = graph[i][j];
    }
  }

  for(int k=0; k<V; k++) {
    for(int i=0; i<V; i++) {
      for(int j=0; j<V; j++) {
        if(dist[i][j] > dist[i][k] + dist[k][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
    }
  }
  show(dist);
}

int main(int argc, char const *argv[]) {
  /* code */
  int graph[V][V] = { {0,   5,  INF, 10},
                        {INF, 0,   3, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
                      };
  floyd(graph);
  return 0;
}
