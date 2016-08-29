#include <bits/stdc++.h>
using namespace std;
int N;

int partition(int arr[], int start, int end) {
  int i = start + 1;
  int piv = arr[start];
  for(int j=start+1; j<=end; j++) {
    if(arr[j] < piv) {
      swap(arr[j], arr[i]);
      i++;
    }
  }
  swap(arr[start], arr[i-1]);
  return i-1;
}

void qSort(int arr[], int start, int end) {
  if(start < end) {
    int p = partition(arr, start, end);
    qSort(arr, start, p-1);
    qSort(arr, p+1, end);
  }
}

void input(int arr[]) {
  for(int i=0; i<N; i++) {
    cin>>arr[i];
  }
}

void output(int arr[]) {
  for(int i=0; i<N; i++) {
    cout<<arr[i]<<" ";
  }
}

int main() {
  cin>>N;
  int arr[N];
  input(arr);
  qSort(arr, 0, N-1);
  output(arr);
}
