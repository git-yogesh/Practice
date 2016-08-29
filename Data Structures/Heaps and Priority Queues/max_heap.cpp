#include <bits/stdc++.h>
using namespace std;

int arr[999];
int n;

void max_heapify(int i) {
	int left = 2*i;
	int right = 2*i + 1;
	int largest = i;
	if(left <= n && arr[left] > arr[i])
		largest = left;
	if(right <= n && arr[right] > arr[largest])
		largest = right;
	if(largest != i) {
		swap(arr[i], arr[largest]);
		max_heapify(largest);
	}
}

void build_maxheap() {
	for(int i=n/2; i>=1; i--) {
		max_heapify(i);
	}
}

int main() {
	cin>>n;
	int i=1;
	while(i<=n) {
		cin>>arr[i];
		i++;
	}
	build_maxheap();
	i=1;
	while(i<=n) {
		cout<<arr[i]<<" ";
		i++;
	}
	cout<<"\n";
	return 0;
}
