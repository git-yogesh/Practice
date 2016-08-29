#include <bits/stdc++.h>
using namespace std;
int arr[999];
int n;
void output();
void bsort() {
	for(int i=0; i<n-1; i++) {
	    for(int j=0; j<n-1-i; j++) {
	      if(arr[j] > arr[j+1]) {
	        swap(arr[j], arr[j+1]);
	        output();
	      }
	    }
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
  bsort();
  output();
}
