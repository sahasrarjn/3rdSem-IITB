#include <bits/stdc++.h>
#include "190050102_1.h"

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	srand(time(NULL));
	int n = 100;
    int a[n];
    for(int i=0; i<n; i++) a[i]=i;
    int corr=0;
    for(int k=0; k<n; k++){
        random_shuffle(a,a+n);
        permutation p(n,a);
        int* t=(p*(-p)).to_array();
        int i;
        for(i=0;i<n; i++) if(t[i]!=i) break;
        if(i==n) corr++;
        delete t;
    }
    cout << "CORRECT: " << corr << '\n';
	cout << "WRONG: " << n-corr << '\n';
}