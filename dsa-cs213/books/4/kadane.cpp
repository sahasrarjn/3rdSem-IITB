#include<bits/stdc++.h>
using namespace std;

#define it(m) for(auto it=m.begin(); it!=m.end(); it++)
#define fori(i, n) for(int i=0; i<n; i++)
#define print(x) cout << x << endl;

int kadane(){
    int n;
    cin >> n;

    int a[n];
    fori(i, n) cin >> a[i];

    int localMax=0, globalMax=INT_MIN;

    for(int i=0; i<n; i++){
        localMax = max(a[i], a[i] + localMax);
        if(localMax > globalMax){
            globalMax = localMax;
        }
    }

    return globalMax;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while(T--)
        cout << kadane() << endl;
}