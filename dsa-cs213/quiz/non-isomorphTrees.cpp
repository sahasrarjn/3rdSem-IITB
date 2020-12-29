#include<iostream>
using namespace std;

long long num_trees(long long n){
	long long T[n+1];
	T[0] = 1;
	for(long long i=0; i<n; i++){
		T[i+1] = 0;
		for(long long j=0; j<i/2+1; j++) T[i+1] += T[j] * T[i-j];
		if(i%2==0) T[i+1] += T[i/2]*(1-T[i/2])/2;
	}
	return T[n];
}

int main(){
	long long n;
	cin >> n;
	for(long long i=1; i<=n; i++){
		cout << i << ": " << num_trees(i) << endl;
	}
}
