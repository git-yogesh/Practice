#include <bits/stdc++.h>
using namespace std;
int N;
int max1;
void output(int out[]);
void cSort(int arr[], int out[]) {
  int aux[max1+1];
  for(int i=0; i<=max1; i++) {
    aux[i] = 0;
  }
  for(int i=0; i<N; i++) {
    aux[arr[i]]++;
  }
  output(aux);
  cout<<endl;
  for(int i=1; i<=max1; i++) {
    aux[i] += aux[i-1];
  }
  output(aux);
  cout<<endl;
  for(int i=0; i<N; i++) {
    out[aux[arr[i]]-1] = arr[i];
    aux[arr[i]]--;
  }
  output(aux);
  cout<<endl;
}

void input(int arr[]) {
  for(int i=0; i<N; i++) {
    cin>>arr[i];
  }
}

void output(int out[]) {
  for(int i=0; i<N; i++) {
    cout<<out[i]<<" ";
  }
}

int main() {
  cin>>N;
  int arr[N];
  cin>>max1;
  int out[N];
  input(arr);
  cSort(arr, out);
  output(out);
}
