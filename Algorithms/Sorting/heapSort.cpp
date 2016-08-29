#include <bits/stdc++.h>
using namespace std;

int arr[999];
int n;
int size;

void max_heapify(int i, int m) {
	int left = 2*i;
	int right = 2*i + 1;
	int largest = i;
	if(left <= m && arr[left] > arr[i]) 
		largest = left;
	if(right <= m && arr[right] > arr[largest]) 
		largest = right;
	if(largest != i) {
		swap(arr[i], arr[largest]);
		max_heapify(largest, m);
	}
}

void build_maxheap() {
	for(int i=size/2; i>=1; i--) {
		max_heapify(i, size);
	}
}

void show() {
	for(int i=1; i<=n; i++) cout<<arr[i]<<" ";
	cout<<endl;
}

void heap_sort() {
	size = n;
	build_maxheap();
	show();
	for(int i=n; i>=2; i--) {
		swap(arr[1], arr[i]);
		size--;
		build_maxheap();
		show();
	}
}

int main() {
	cin>>n;
	int i=1;
	while(i<=n) {
		cin>>arr[i];
		i++;
	}
	//build_maxheap();
	heap_sort();
	cout<<"\n";
	return 0;
}
