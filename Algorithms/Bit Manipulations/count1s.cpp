#include <bits/stdc++.h>
using namespace std;

int count1(int n) {
  int count = 0;
  while(n) {
    n &= (n-1);
    count++;
  }
  return count;
}

int main() {
  int n;
  cin>>n;
  cout<<count1(n);
  return 0;
}
