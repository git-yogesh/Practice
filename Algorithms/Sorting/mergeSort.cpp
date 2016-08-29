#include <bits/stdc++.h>
using namespace std;
int N;

void merge(int arr[], int start, int mid, int end) {
  int aux[end-start+1];
  int p = start;
  int q = mid + 1;
  int k = 0;
  for(int i=start; i<=end; i++) {
    if(p > mid) {
      aux[k++] = arr[q++];
    }
    else if(q > end) {
      aux[k++] = arr[p++];
    }
    else if(arr[p] < arr[q]) {
      aux[k++] = arr[p++];
    }
    else aux[k++] = arr[q++];
  }
  for(int i=0; i<k; i++) {
    arr[start++] = aux[i];
  }
}

void mSort(int arr[], int start, int end) {
  if(start < end) {
    int mid = (start + end) / 2;
    mSort(arr, start, mid);
    mSort(arr, mid+1, end);
    merge(arr, start, mid, end);
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
  mSort(arr, 0, N-1);
  output(arr);
}
