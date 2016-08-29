#include <bits/stdc++.h>
using namespace std;
int top = -1;
void push(int stack[], int x, int n) {
	if(top == n-1) cout<<"Stack full";
	else {
		top++;
		stack[top] = x;
	}
}

void pop(int stack[]) {
	if(top == -1) cout<<"Stack empty";
	else{
		top--;
	}
}

void show(int stack[], int n) {
	for(int i=0; i<n; i++) {
		cout<<stack[i];
	}
}

int main() {
	int stack[999];
	int n, x;
	cin>>n;
	int choice;
	int t;
	cin>>t;
	while(t--) {
		cout<<"1. Push 2. Pop"<<"\n";
		cin>>choice;
		if(choice == 1) {
			cin>>x;
			push(stack, x, n);
			show(stack, top);
		}
		if(choice == 2) {
			pop(stack);
			show(stack, top);
		}
	}
	return 0;
}
