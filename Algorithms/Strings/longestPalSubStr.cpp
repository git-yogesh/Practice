#include <bits/stdc++.h>
using namespace std;

void print(string s, int start, int end) {
  for(int i=start; i<end; i++) {
    cout<<s[i];
  }
  cout<<endl;
}

int find(string s) {
  int n = s.length();
  bool table[n][n];
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      table[i][j] = false;
    }
  }
  int maxlen = 1;
  for(int i=0; i<n; i++) {
    table[i][i] = true;
  }
  int start = 0;
  for(int i=0; i<n-1; i++) {
    if(s[i] == s[i+1]) {
      table[i][i+1] = true;
      maxlen = 2;
      start = i;
    }
  }

  for(int k=3; k<=n; k++) {
    for(int i=0; i<n-k+1; i++) {
      int j=i+k-1;
      if(table[i+1][j-1] && s[i]==s[j]) {
        table[i][j] = true;
        if(k > maxlen) {
          maxlen = k;
          start = i;
        }
      }
    }
  }
  print(s, start, start+maxlen);
  return maxlen;
}

int main() {
  string s;
  cin>>s;
  int len = find(s);
  return 0;
}
