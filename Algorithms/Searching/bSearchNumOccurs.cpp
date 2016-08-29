#include <bits/stdc++.h>
using namespace std;
int result_first;
int result_last;

int firstOccur(int arr[], int left, int right, int item) {
  int mid;
  if(left<=right) {
    mid = (left+right)/2;
    if(arr[mid] == item) {
      result_first = mid;
      return firstOccur(arr, left, mid-1, item);
    }
    else if(arr[mid] < item) return firstOccur(arr, mid+1, right, item);
    else return firstOccur(arr, left, mid-1, item);
  }
  else return result_first;
}

int lastOccur(int arr[], int left, int right, int item) {
  int mid;
  if(left<=right) {
    mid = (left+right)/2;
    if(arr[mid] == item) {
      result_last = mid;
      return lastOccur(arr, mid+1, right, item);
    }
    else if(arr[mid] < item) return lastOccur(arr, mid+1, right, item);
    else return lastOccur(arr, left, mid-1, item);
  }
  else return result_last;
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
  cout<<(lastOccur(arr, left, right, item) - firstOccur(arr, left, right, item))+1<<endl;
  return 0;
}
