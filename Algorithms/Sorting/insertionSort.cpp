#include <bits/stdc++.h>
using namespace std;
int n;
void iSort(int arr[]) {
  int j, temp;
  for(int i=1; i<n; i++) {
    temp = arr[i];
    for(j=i-1; j>=0 && arr[j] > temp; j--) {
      arr[j+1] = arr[j];
    }
    arr[j+1] = temp;
  }
}

int main () {
  cin>>n;
  int arr[n];
  for(int i=0; i<n; i++) {
    cin>>arr[i];
  }
  iSort(arr);
  for(int i=0; i<n; i++) {
    cout<<arr[i]<<" ";
  }
  return 0;
}
