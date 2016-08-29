#include <iostream>
using namespace std;

void sievefun(int M, int N) {
	bool isPrime[M-N+1];
	for(int i=0; i <= N; i++) {
		isPrime[i] = true;
	}
	
	isPrime[0] = false;
	isPrime[1] = false;
	
	for(int i=M; i*i <= N; i++) {
		if(isPrime[i] == true) {
			for(int j = i*i; j <= N; j += i) {
				isPrime[j] = false;
			}
		}
	}
	for(int i=M; i <= N; i++) {
		if(isPrime[i] == true) cout<<i<<" ";
	}
}

int main() {
	int m;
	int n;
	int t;
	cin >> t;
	while(t--) {
		cin>>m>>n;
		sievefun(m,n);
	}
	return 0;
}
