#include <bits/stdc++.h>
using namespace std;

int bSearch(int arr[], int left, int right, int item) {
  int mid;
  if(left<=right) {
    mid = (left+right)/2;
    if(arr[mid] == item) return mid;
    else if(arr[mid] < item) return bSearch(arr, mid+1, right, item);
    else return bSearch(arr, left, mid-1, item);
  }
  else return -1;
}

int main() {
  int n;
  cin>>n;
  int arr[n];
  int i=0;
  for(i=0; i<n; i++) {
    cin>>arr[i];
  }
  int right = i - 1;
  int left = 0;
  int item;
  cin>>item;
  cout<<bSearch(arr, left, right, item);
  return 0;
}
