#include <bits/stdc++.h>
using namespace std;

int arr[999];
int n;

void sSort() {
  int min;
  for(int i=0; i<n; i++) {
    min = i;
    for(int j=i+1; j<n; j++) {
      if(arr[min] > arr[j]) min = j;
    }
    swap(arr[i], arr[min]);
  }
}

void input() {
  for(int i=0; i<n; i++) {
    cin>>arr[i];
  }
}

void output() {
  for(int i=0; i<n; i++) {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

int main() {
  cin>>n;
  input();
  sSort();
  output();
}
