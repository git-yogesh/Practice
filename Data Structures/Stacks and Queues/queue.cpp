#include <bits/stdc++.h>
using namespace std;

char que[999];
int front = 0;
int rear = 0;
int n; 

void enqueue(int x) {
	if(rear == n) cout<<"Queue full\n";
	else {
		que[rear] = x;
		rear++;
	}
}

void dequeue() {
	if(front == rear) cout<<"Empty\n";
	else {
		n++;
		enqueue(que[front]);
		que[front] = 0; 
		front++;		
	}
}

int main() {
	int i=0;
	char x;
	cin>>n;
	while(i != n) {
		cin>>x;
		enqueue(x);
		i++;
	}
	int t;
	cin>>t;
	while(t-- && front != rear) {
		dequeue();
	}
	for(int i=0; i<n; i++) {
		cout<<que[i];
	}
	cout<<endl;
	return 0;
}
