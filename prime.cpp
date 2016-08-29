#include <iostream>
using namespace std;

void checkPrime(int N) {
	int count = 0;
	for(int i=1; i*i <= N; i++) {
		if(N%i == 0) {
			if(i*i == N) count++;
			else count += 2;
		}
	}
	
	if(count == 2) cout<<N<<" is a prime number. "<<endl;
	else cout<<N<<" is not a prime number."<<endl;
}

int main() {
	int n;
	cin>>n;
	checkPrime(n);
	return 0;
}
