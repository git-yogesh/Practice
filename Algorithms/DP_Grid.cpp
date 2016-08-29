#include <bits/stdc++.h>
using namespace std;
#define F(i, a, b) for(int i = (int) a; i <= b; i++)
#define RF(i, a, b) for(int i = (int) a; i >= b; i--)

int main() {
  //input cost matrix
  int X, Y;
  cin>>X>>Y;
  int i, j;
  int cost[X][Y];
  int minCost[X][Y];
  F(i, 0, X-1) {
    F(j, 0, Y-1) {
      cin>>cost[i][j];
    }
  }

  minCost[0][0] = cost[0][0];
  F(i, 1, X-1) {
    minCost[i][0] = minCost[i-1][0] + cost[i][0];
  }
  F(i, 1, Y-1) {
    minCost[0][j] = minCost[0][j-1] + cost[0][j];
  }
  F(i, 1, X-1) {
    F(j, 1, Y-1) {
      minCost[i][j] = min(minCost[i-1][j], minCost[i][j-1]) + cost[i][j];
    }
  }
  cout<<"MinCost = "<<minCost[X-1][Y-1];
}
